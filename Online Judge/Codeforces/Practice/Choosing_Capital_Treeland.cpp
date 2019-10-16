#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
vector<int> g[N];
map<pair<int,int>, int> mp;
int pat[N], dist[N], ans[N];
int upp = 0;

// RED -> Go Towards Root (up)
// ans[i] = AllRed - 2 * RedPath[v] + DistPath[v]

void dfs(int u, int p, int cur, int h) {
    pat[u] = cur;
    dist[u] = h;
    for (auto e : g[u]) {
        if (e == p) continue;
        int k = mp[{e, u}];
        upp += k;
        dfs(e, u, cur + k, h + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}]++;
    }
    dfs(1, 0, 0, 0);
    int mini = 1e9;
    for (int i = 1; i <= n; i++) {
        ans[i] = upp - 2 * pat[i] + dist[i];
        mini = min(mini, ans[i]);
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == mini) {
            v.push_back(i);
        }
    }
    int len = v.size();
    cout << mini << '\n';
    for (int i = 0; i < len; i++) {
        cout << v[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}
