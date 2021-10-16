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
    
    int k;
    cin >> k;
    int n;
    cin >> n;
    map<long long, int> mp;
    for (int i = 0; i < n; i++) {
        long long v;
        string s;
        cin >> v >> s;
        if (s == "white" || s == "yellow") {
            mp[v] = 0;
        } else if (s == "green" || s == "blue") {
            mp[v] = 1;
        } else if (s == "red" || s == "orange") {
            mp[v] = 2;
        }
        while (v > 1) {
            v /= 2;
            if (mp.count(v) == 0) {
                mp[v] = -1;
            }
        }
    }
    long long nodes = (1LL << k) - 1;
    mint ans = mint(2).pow(nodes - n);
    ans *= mint(2).pow(nodes - (int) mp.size());
    function<vector<mint>(long long)> dfs = [&](long long u) {
        vector<mint> ret(3, 1);
        for (long long v : {2 * u, 2 * u + 1}) {
            if (mp.count(v) == 0) {
                continue;
            }
            auto cur = dfs(v);
            ret[0] *= (cur[1] + cur[2]);
            ret[1] *= (cur[0] + cur[2]);
            ret[2] *= (cur[0] + cur[1]);
        }
        if (mp[u] != -1) {
            for (int i = 0; i < 3; i++) {
                if (i != mp[u]) {
                    ret[i] = 0;
                }
            }
        }
        return ret;
    };
    auto res = dfs(1);
    ans *= (res[0] + res[1] + res[2]);
    cout << ans << '\n';

    return 0;
}