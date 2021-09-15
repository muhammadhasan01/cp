#include <bits/stdc++.h>

using namespace std;

struct mint {
    const int MOD = 1e9 + 7;
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
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<vector<mint>> f(n + 1, vector<mint>(n + 1));
    for (int i = 1; i <= n; i++) {
        f[0][i] = 1;
    }
    mint inv2 = mint(2).inv();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) * inv2;
        }
    }
    mint ans = 0;
    int bound = ceil(log2(n)) + 3;
    auto solve = [&](int root) -> void {
        vector<vector<int>> up(n + 1, vector<int>(bound));
        vector<int> tin(n + 1), tout(n + 1), dist(n + 1);
        int tim = 0;
        function<void(int, int, int)> dfs = [&](int u, int p, int d) {
            up[u][0] = p;
            for (int i = 1; i < bound; i++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
            tin[u] = ++tim;
            dist[u] = d;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u, 1 + d);
            }
            tout[u] = ++tim;
        };
        auto is_ancestor = [&](int u, int v) -> bool {
            return (tin[u] <= tin[v] && tout[u] >= tout[v]);
        };
        auto lca = [&](int u, int v) -> int {
            if (is_ancestor(u, v)) {
                return u;
            }
            if (is_ancestor(v, u)) {
                return v;
            }
            for (int i = bound - 1; i >= 0; i--) {
                if (!is_ancestor(up[v][i], u)) {
                    v = up[v][i];
                }
            }
            return up[v][0];
        };
        dfs(root, root, 0);
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v < u; v++) {
                int w = lca(u, v);
                ans += f[dist[u] - dist[w]][dist[v] - dist[w]];
            }
        }
    };
    for (int u = 1; u <= n; u++) {
        solve(u);
    };
    cout << ans / n << '\n';
    
    return 0;
}