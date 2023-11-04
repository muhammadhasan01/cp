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

const int N = 1e6 + 5;
 
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int numThree = 0;
    int numTwo = 0;
    for (int i = 0; i < n; i += 3) {
        vector<int> cur = {a[i], a[i + 1], a[i + 2]};
        sort(cur.begin(), cur.end());
        if (cur[0] == cur[2]) {
            numThree++;
        } else if (cur[0] == cur[1]) {
            numTwo++;
        }
    }
    mint res = C(n / 3, n / 6) * mint(3).pow(numThree) * mint(2).pow(numTwo);
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}