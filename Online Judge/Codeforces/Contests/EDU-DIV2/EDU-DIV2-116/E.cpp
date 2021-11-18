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

const int N = 1e3 + 5;
 
mint fact[N];
mint invf[N];
 
mint C(int a, int b) {
    if (a < b) return 0;
    return fact[a] * invf[b] * invf[a - b];
}
 
void init() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
        invf[i] = fact[i].inv();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    int n, x;
    cin >> n >> x;
    vector<vector<mint>> dp(n + 1, vector<mint>(x + 1));
    for (int val = 1; val <= x; val++) {
        dp[1][val] = val;
    }
    for (int len = 2; len <= n; len++) {
        for (int val = len - 1; val <= x; val++) {
            for (int alive = 1; alive <= len; alive++) {
                mint choose_alive = C(len - 1, alive - 1);
                mint dead_ways = mint(len - 1).pow(len - alive);
                dp[len][val] += choose_alive * dead_ways * dp[alive][val - (len - 1)];
            }
        }
    }
    cout << mint(x).pow(n) - dp[n][x] * n << '\n';
    
    return 0;
}