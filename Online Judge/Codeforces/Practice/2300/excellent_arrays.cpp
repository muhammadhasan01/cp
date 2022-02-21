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

const int INF = 1e9;
const int N = 2e5 + 5;
 
mint fact[N];
mint invf[N];
 
mint C(int a, int b) {
    if (a < b) return 0;
    mint ret = fact[a] * invf[b];
    ret = (ret * invf[a - b]);
    return ret;
}
 
void init() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
        invf[i] = fact[i].inv();
    }
}


void solve() {
    int n, L, R;
    cin >> n >> L >> R;
    int min_val = 0;
    {
        auto can = [&](int x) -> bool {
            for (int i = 1; i <= n; i++) {
                int l = L - i;
                int r = R - i;
                if (l <= -x && x <= r) {
                    continue;
                }
                return false;
            }
            return true;
        };
        int l = 1, r = INF;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                l = mid + 1;
                min_val = mid;
            } else {
                r = mid - 1;
            }
        }
    }
    int max_val = min_val + 1;
    {
        auto can = [&](int x) -> bool {
            for (int i = 1; i <= n; i++) {
                int l = L - i;
                int r = R - i;
                if (l <= -x || x <= r) {
                    continue;
                }
                return false;
            }
            return true;
        };
        int l = min_val, r = INF;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                l = mid + 1;
                max_val = mid;
            } else {
                r = mid - 1;
            }
        }
    }
    vector<int> needs = {n / 2};
    if (n % 2 == 1) {
        needs.emplace_back(n / 2 + 1);
    }
    mint ans = 0;
    for (int need : needs) {
        ans += (mint(min_val) * C(n, need));
        for (int x = min_val + 1; x <= min(min_val + n, max_val); x++) {
            // find (-x, x]
            int num_p = max(0, min(R - x, L + x - 1));
            // find [-x, x)
            int num_n = max(0, n - max(R - x, L + x - 1));
            int exact = num_n + num_p;
            if (exact > n || exact < 0 || num_p > need) {
                continue;
            }
            ans += C(n - exact, need - num_p);
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}