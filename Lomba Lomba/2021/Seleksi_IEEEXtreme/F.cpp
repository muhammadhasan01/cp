#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int M = 2 * N;
const int B = 200;

int n;
int eul[M];
vector<int> adj[N];
int dp[N][B];
int tin[N], tout[N], tim = 0;
int pos[N];

void dfs(int u, int p) {
    for (int x = 1; x < B; x++) {
        if (u % x == 0) {
            dp[u][x]++;
        }
    }
    eul[++tim] = u;
    tin[u] = tim;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        for (int x = 1; x < B; x++) {
            dp[u][x] += dp[v][x];
        }
    }
    eul[++tim] = u;
    tout[u] = tim;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    for (int i = 1; i <= 2 * n; i++) {
        pos[eul[i]] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        int u, x;
        cin >> u >> x;
        if (x < B) {
            cout << dp[u][x] << '\n';
        } else {
            int l = tin[u];
            int r = tout[u];
            int ans = 0;
            for (int i = 1; i < N; i++) {
                if (1LL * x * i > (long long) n) {
                    break;
                }
                int val = x * i;
                if (l <= pos[val] && pos[val] <= r) {
                    ++ans;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}