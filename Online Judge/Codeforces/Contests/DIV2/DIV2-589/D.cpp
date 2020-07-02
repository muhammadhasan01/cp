#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
vector<int> g[N];
int ans[N];
map<vector<int>, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (mp[g[i]] == 0) {
            mp[g[i]] = ++cnt;
            ans[i] = cnt;
            v.push_back(i);
        } else {
            ans[i] = mp[g[i]];
        }
        if (cnt > 3) {
            puts("-1");
            return 0;
        }
    }
    if (cnt != 3) {
        puts("-1");
        return 0;
    }
    for (auto e : v) {
        if ((int) g[e].size() == 0) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
