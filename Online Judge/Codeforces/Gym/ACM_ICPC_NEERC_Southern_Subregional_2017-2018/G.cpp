#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 3e5 + 10;

int n, m, s;
vector <int> dir[N], undir[N];
vector <pii> v;

map<pii, int> ans1, ans2; // 1 == in, 2 == out

bool vis[N];
int cnt1, cnt2;

void dfsmax(int node){
    if (vis[node]) return;
    vis[node] = 1;
    cnt1++;

    for (auto dest : dir[node]){
        if (!vis[dest]){
            dfsmax(dest);
        }
    }

    for (auto dest : undir[node]){
        if (vis[dest]){
            if (!ans1[mp(node, dest)]){
                ans1[mp(node, dest)] = 2;
                ans1[mp(dest, node)] = 1;
            }
            continue;
        }

        if (!ans1[mp(node, dest)] || ans1[mp(node, dest)]==2){
            ans1[mp(node, dest)] = 2;
            ans1[mp(dest, node)] = 1;
            dfsmax(dest);
        }
    }
}

void dfsmin(int node){
    if (vis[node]) return;
    vis[node] = 1;
    cnt2++;

    for (auto dest : dir[node]){
        if (!vis[dest]){
            dfsmin(dest);
        }
    }

    for (auto dest : undir[node]){
        if (vis[dest]){
            if (!ans2[mp(node, dest)]){
                ans2[mp(node, dest)] = 2;
                ans2[mp(dest, node)] = 1;
            }
            continue;
        }

        if (!ans2[mp(node, dest)] || ans2[mp(node, dest)]==2){
            ans2[mp(node, dest)] = 1;
            ans2[mp(dest, node)] = 2;
            // dfsmax(dest);
        }
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i=0;i<m;i++){
        int tipe, a, b;
        cin >> tipe >> a >> b;
        if (tipe==1){
            dir[a].pb(b);
        } else{
            v.pb(mp(a,b));
            undir[a].pb(b);
            undir[b].pb(a);
        }
    }

    dfsmax(s);
    for (int i=0;i<N;i++){
        vis[i] = 0;
    }
    dfsmin(s);

    cout << cnt1 << el;
    for (auto x : v){
        if (ans1[x]==1){
            cout << '-';
        } else{
            cout << '+';
        }
    }
    cout << el;
    cout << cnt2 << el;
    for (auto x : v){
        if (ans2[x]==1){
            cout << '-';
        } else{
            cout << '+';
        }
    }
    cout << el;

    return 0;
}
