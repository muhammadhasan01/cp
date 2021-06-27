#include <bits/stdc++.h>

using namespace std;

const int K = 19;
const int N = (1 << K);

int k, n, q;
char s[N];
vector<int> adj[N];
int dp[N], up[N];

void dfs(int u) {
    if (adj[u].empty()) {
        dp[u] = (s[u] == '?' ? 2 : 1);
        return;
    }
    int x = adj[u][0], y = adj[u][1];
    dfs(x); dfs(y);
    if (x > y) swap(x, y);
    dp[u] = 0;
    if (s[u] == '?' || s[u] == '0') {
        dp[u] += dp[x];
    }
    if (s[u] == '?' || s[u] == '1') {
        dp[u] += dp[y];
    }
}

void upd(int u, char cc) {
    s[u] = cc;
    while (true) {
        if (u > n) break;
        if (adj[u].empty()) {
            dp[u] = (s[u] == '?' ? 2 : 1);
        } else {
            int x = adj[u][0], y = adj[u][1];
            if (x > y) swap(x, y);
            dp[u] = 0;
            if (s[u] == '?' || s[u] == '0') {
                dp[u] += dp[x];
            }
            if (s[u] == '?' || s[u] == '1') {
                dp[u] += dp[y];
            }
        }
        u = up[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    n = (1 << k) - 1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int num = 1;
    for (int i = k - 1; i >= 0; i--) {
        for (int it = 0; it < (1 << i); it++, num++) {
            int par = num + (1 << i) - (it + 1) / 2;
            up[num] = par;
            adj[par].emplace_back(num);
        }
    }
    dfs(n);
    cin >> q;
    while (q--) {
        int p; char cc;
        cin >> p >> cc;
        upd(p, cc);
        cout << dp[n] << '\n';
    }

    return 0;
}