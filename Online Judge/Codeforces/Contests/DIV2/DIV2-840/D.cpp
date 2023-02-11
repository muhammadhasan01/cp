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

void solve() {
    int n, pi, pj, vi, vj;
    cin >> n >> pi >> pj >> vi >> vj;
    pi--, pj--, vi--, vj--;
    auto isValid = [&](int p, int v) -> bool {
        if (p == pi && v != vi) {
            return false;
        }
        if (p == pj && v != vj) {
            return false;
        }
        return true;
    };
    vector<vector<mint>> dp(n, vector<mint>(n));
    for (int i = 1; i < n - 1; i++) {
        if (isValid(i, n - 1)) {
            dp[i][i] = 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            int val = n - 1 - (j - i + 1);
            if (i > 0) {
                if (isValid(i - 1, val)) {
                    dp[i - 1][j] += dp[i][j];
                }
            }
            if (j + 1 < n) {
                if (isValid(j + 1, val)) {
                    dp[i][j + 1] += dp[i][j];
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}