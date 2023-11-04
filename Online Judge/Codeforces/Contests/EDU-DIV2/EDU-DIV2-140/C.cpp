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

void solve() {
    int n;
    cin >> n;
    vector<int> X(n + 1);
    vector<int> Y(n + 1);
    for (int i = 1; i <= n; i++) {
        X[i] = 1;
        Y[i] = i;
    }
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (a[i][j] == 1) {
                Y[j] = min(Y[j], i);
            } else if (a[i][j] == 2) {
                X[j] = max(X[j], i + 1);
            } 
        }
    }
    // dp[r][l] = num of ways to form s[l ... r] such that it's valid 
    //            and s[l] is the leftmost character such that s[l] = s[r]  
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
    if (a[1][1] != 2) {
        dp[1][1] = 2;
    }
    for (int r = 2; r <= n; r++) {
        for (int l = X[r]; l <= Y[r]; l++) {
            if (l < r) {
                dp[r][l] += dp[r - 1][l];
            }
        }
        if (X[r] > r || Y[r] < r) {
            continue;
        }
        for (int l = 1; l < r; l++) {
            dp[r][r] += dp[r - 1][l];
        }
    }
    mint ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}