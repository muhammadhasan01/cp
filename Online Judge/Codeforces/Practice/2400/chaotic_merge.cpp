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
    
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(m + 1, vector<mint>(2, 0)));
    mint ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i < n) {
                dp[i + 1][j][0] += 1;
            }
            if (j < m) {
                dp[i][j + 1][1] += 1;
            }
            if (0 < i && i < n && s[i - 1] != s[i]) {
                dp[i + 1][j][0] += dp[i][j][0];
            }
            if (0 < j && i < n && t[j - 1] != s[i]) {
                dp[i + 1][j][0] += dp[i][j][1];
            }
            if (0 < i && j < m && s[i - 1] != t[j]) {
                dp[i][j + 1][1] += dp[i][j][0];
            }
            if (0 < j && j < m && t[j - 1] != t[j]) {
                dp[i][j + 1][1] += dp[i][j][1];
            }
            ans += dp[i][j][0];
            ans += dp[i][j][1];
        }
    }
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && s[j] != s[j + 1]) {
            j++;
        }
        int len = j - i + 1;
        mint cur = mint(1LL * len * (len + 1) / 2) * mint(m + 1);
        ans -= cur;
        i = j;
    }
    for (int i = 0; i < m; i++) {
        int j = i;
        while (j + 1 < m && t[j] != t[j + 1]) {
            j++;
        }
        int len = j - i + 1;
        mint cur = mint(1LL * len * (len + 1) / 2) * mint(n + 1);
        ans -= cur;
        i = j;
    }
    cout << ans << '\n';
    
    return 0;
}