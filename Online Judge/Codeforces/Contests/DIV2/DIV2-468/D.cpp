#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int par[N];
vector<int> g[N];
vector<int> depth[N];
int ans = 0;

void dfs(int u, int h) {
    depth[h].emplace_back(u);
    for (auto v : g[u]) {
        dfs(v, h + 1);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].emplace_back(i);
    }
    dfs(1, 0);
    int ans = 0;
    for (int h = 0; h < n; h++) {
        int len = depth[h].size();
        ans += (len & 1);
    }
    cout << ans << '\n';

    return 0;
}