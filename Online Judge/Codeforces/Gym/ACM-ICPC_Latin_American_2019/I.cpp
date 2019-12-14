#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 1e9 + 7;
int n, l;
vector<int> g[N];
vector<int> rg[N];
long long dp[N];
bool vis[N];
int deg[N];
int res;

void dfs(int u) {
    vis[u] = 1;
    for (auto e : g[u]) {
        if (e <= l) {
            rg[e].push_back(u);
            deg[u]++;
        }
        if (vis[e] == 0) dfs(e);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    for (int i = 1; i <= l; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int v;
            cin >> v;
            g[i].push_back(v);
            if (v > l) dp[i]++;
        }
    }
    dfs(1);
    queue<int> q;
    for (int i = 1; i <= l; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : rg[x]) {
            dp[y] += dp[x];
            dp[y] %= M;
            if (--deg[y] == 0) {
                q.push(y);
            }
        }
    }
    for (int i = l + 1; i <= n; i++) {
        if (vis[i]) res++;
    }
    cout << dp[1] << " " << res << '\n';

    return 0;
}
