// author : m.hasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;

int n;
vector<int> g[N];
int stuck[N];
long long dp[N][2];
long long T[N][2], F[N][2];

void DP(int u) {
    int len = g[u].size();
    if (len == 0) {
        dp[u][1] = 3;
        dp[u][0] = 1;
        return;
    } else if (len == 1) {
        int v = g[u][0];
        DP(v);
        dp[u][0] = dp[v][1];
        dp[u][1] = (2LL * dp[v][0] + dp[v][1]) % M;
    } else if (len == 2) {
        int v = g[u][0], w = g[u][1];
        DP(v); DP(w);
        dp[u][0] = (dp[v][1] * dp[w][1]) % M;
        dp[u][1] = (dp[v][0] * dp[w][0]) % M;
        dp[u][1] = (dp[u][1] + dp[v][0] * dp[w][1]) % M;
        dp[u][1] = (dp[u][1] + dp[v][1] * dp[w][0]) % M; 
    }
}

void merge(int u, int v, int w) {
    // Truth value
    T[u][0] = (T[u][0] + T[v][1] * T[w][1]) % M;
    T[u][1] = (T[u][1] + T[v][0] * T[w][1]) % M;
    T[u][1] = (T[u][1] + T[v][1] * T[w][0]) % M;
    T[u][1] = (T[u][1] + T[v][0] * T[w][0]) % M;
    // False & Truth Value
    T[u][1] = (T[u][1] + F[v][0] * T[w][0] + F[w][0] * T[v][0]) % M;
    F[u][1] = (F[u][1] + F[v][0] * T[w][1] + F[w][0] * T[v][1]) % M;
    T[u][1] = (T[u][1] + F[v][1] * T[w][0] + F[w][1] * T[v][0]) % M;
    F[u][0] = (F[u][0] + F[v][1] * T[w][1] + F[w][1] * T[v][1]) % M;
    // False value
    F[u][1] = (F[u][1] + F[v][0] * F[w][0]) % M;
    T[u][1] = (T[u][1] + F[v][1] * F[w][0]) % M;
    T[u][1] = (T[u][1] + F[v][0] * F[w][1]) % M;
    F[u][0] = (F[u][0] + F[v][1] * F[w][1]) % M;
}

void hmm(int u, int v) {
    // Truth value
    T[u][0] = (T[u][0] + T[v][1]) % M;
    T[u][1] = (T[u][1] + 2LL * T[v][0] + T[v][1]) % M;
    // False value
    T[u][1] = (T[u][1] + F[v][0]) % M;
    F[u][1] = (F[u][1] + F[v][0]) % M;
    T[u][1] = (T[u][1] + F[v][1]) % M;
    F[u][0] = (F[u][0] + F[v][1]) % M;
}

void dfs(int u) {
    if (stuck[u] == 1) {
        T[u][0] = 0;
        T[u][1] = dp[u][1];
        F[u][0] = 0;
        F[u][1] = dp[u][0];
    } else if (stuck[u] == 0) {
        T[u][0] = dp[u][0];
        T[u][1] = 0;
        F[u][0] = dp[u][1];
        F[u][1] = 0;
    } else {
        int len = g[u].size();
        if (len == 0) {
            T[u][0] = 1;
            T[u][1] = 3;
        } else if (len == 1) {
            int v = g[u][0];
            dfs(v);
            merge(u, v, 0);
        } else if (len == 2) {
            int v = g[u][0], w = g[u][1];
            dfs(v); dfs(w);
            merge(u, v, w);
        }
    }
}


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, f;
        cin >> x >> y >> f;
        stuck[i] = f;
        if (x) g[i].emplace_back(x);
        if (y) g[i].emplace_back(y);
    }
    DP(1);
    T[0][0] = T[0][1] = 1;
    dfs(1);
    long long ans = (F[1][0] + F[1][1]);
    ans = (ans % M + M) % M;
    cout << ans << '\n';

    return 0;
}