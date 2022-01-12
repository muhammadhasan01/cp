#include <bits/stdc++.h>

using namespace std;

struct mint {
    const int MOD = 1e9 + 7;
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

const int N = 3e3 + 5;

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

mint G(int x) {
    return mint(2).pow(1LL * x * (x - 1) / 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    int n;
    cin >> n;
    vector<mint> num_c(n + 1);
    num_c[1] = 1;
    for (int i = 2; i <= n; i++) {
        mint cur = G(i);
        mint res = 0;
        for (int k = 1; k < i; k++) {
            res += mint(k) * C(i, k) * num_c[k] * G(i - k);
        }
        res = (res / i);
        num_c[i] = cur - res;
    }
    vector<mint> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k < i; k++) {
            int rem = i - k;
            mint num_ways = C(i - 1, k - 1);
            dp[i] += num_c[k] * num_ways * (dp[rem] + G(rem));
        }
        dp[i] += num_c[i];
    }
    cout << dp[n] << '\n';

    return 0;
}