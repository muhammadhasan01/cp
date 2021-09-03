#include <bits/stdc++.h>

using namespace std;

int MOD;

struct mint {
    int x;

    mint(int _x) : x((_x % MOD + MOD) % MOD) {}

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
    cin >> n >> MOD;
    vector<mint> dp(n + 5);
    vector<mint> suf(n + 5);
    dp[n] = suf[n] = 1;
    mint sum = 0;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = suf[i + 1];
        for (int j = 2; j <= n; j++) {
            if (1LL * i * j > (long long) n) {
                break;
            }
            int l = i * j;
            int r = min(n, (i + 1) * j - 1);
            dp[i] += suf[l] - suf[r + 1];
        }
        suf[i] = suf[i + 1] + dp[i];
    }
    cout << dp[1] << '\n';
    
    return 0;
}