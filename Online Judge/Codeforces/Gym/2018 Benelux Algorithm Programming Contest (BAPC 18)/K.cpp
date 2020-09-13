#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, root;
vector<int> adj[N];
vector<int> leaf;

int cab[N];

void dfs(int node, int p){
    if (adj[node].size() == 1){
        leaf.pb(node);
        return;
    }
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs(x, node);
    }
}
int tcab;
void dfs_cab(int node, int p){
    cab[node] = tcab;
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_cab(x, node);
    }
}
vector<int> vcab[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> root;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(root, root);
    for (auto x : adj[root]){
        tcab = x;
        dfs_cab(x, root);
    }
    for (auto x : leaf){
        vcab[cab[x]].pb(x);
    }
    vector<pii> ans;
    {
        set<pii> setdah;
        for (auto x : leaf){
            setdah.insert(mp((int)vcab[cab[x]].size(), cab[x]));
        }
        while (setdah.size() > 1){
            auto fr = *setdah.begin();
            auto bc = *setdah.rbegin();

            setdah.erase(fr);
            setdah.erase(bc);
            int a = vcab[fr.se].back();
            int b = vcab[bc.se].back();
            vcab[fr.se].pop_back();
            vcab[bc.se].pop_back();
            ans.pb(mp(a, b));
            if (vcab[fr.se].size()){
                setdah.insert(mp((int)vcab[fr.se].size(), fr.se));
            }
            if (vcab[bc.se].size()){
                setdah.insert(mp((int)vcab[bc.se].size(), bc.se));
            }
        }
        if (setdah.size()){
            int pos = setdah.begin()->se;
            for (auto x : vcab[pos]){
                ans.pb(mp(x, root));
            }
        }
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}