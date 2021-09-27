#include <bits/stdc++.h>

using namespace std;

struct mint {
    const int MOD = 998244353;
    int x;

    mint(int _x) : x((_x % MOD + MOD) % MOD) {}
    mint(long long _x) : x((_x % MOD + MOD) % MOD) {}

    mint() : x(0) {}

    mint &operator=(const mint &rhs) {
        x = rhs.x;
        return *this;
    }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = mint(1);
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator+=(const mint &rhs) {
        x += rhs.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }

    mint &operator-=(const mint &rhs) {
        x -= rhs.x;
        if (x < 0)
            x += MOD;
        return *this;
    }

    mint &operator*=(const mint &rhs) {
        unsigned long long z = x;
        z *= rhs.x;
        x = (unsigned int)(z % MOD);
        return *this;
    }

    mint &operator/=(const mint &rhs) {
        return *this = *this * rhs.inv();
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }

    friend mint operator/(const mint &lhs, const mint &rhs) {
        return mint(lhs) /= rhs;
    }

    friend ostream& operator<<(ostream &os, const mint &m) {
        return os << m.x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<vector<mint>> dp(n, vector<mint>(n));
    function<int(int, int)> dfs = [&](int u, int p) {
        dp[u][0] = 1;
        int h = 0;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            int ch = dfs(v, u);
            vector<mint> tmp(max(h, ch + 1) + 1);
            for (int i = 0; i <= h; i++) {
                for (int j = 0; j <= ch; j++) {
                    if (i + j + 1 <= k) {
                        tmp[max(i, j + 1)] += (dp[u][i] * dp[v][j]);
                    }
                    if (i <= k && j <= k) {
                        tmp[i] += (dp[u][i] * dp[v][j]);
                    }
                }
            }
            h = max(h, ch + 1);
            for (int i = 0; i <= h; i++) {
                dp[u][i] = tmp[i];
            }
        }
        return h;
    };
    dfs(0, 0);
    mint ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += dp[0][i];
    }
    cout << ans << '\n';
    
    return 0;
}