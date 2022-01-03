#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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

const int N = 1e4 + 5;
 
mint fact[N];
mint invf[N];

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        cout << 1 << '\n';
        return 0;
    }
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pos.emplace_back(i);
        }
    }
    int len = pos.size();
    auto get_left = [&](int i) -> int {
        if (i == 0) {
            return 0;
        }
        return pos[i - 1] + 1;
    };
    auto get_right = [&](int i) -> int {
        if (i == len - 1) {
            return n - 1;
        }
        return pos[i + 1] - 1;
    };
    auto get_count = [&](int L, int R, int one) -> mint {
        int sz = R - L + 1;
        int zero = sz - one;
        mint ret = fact[sz] * invf[one] * invf[zero] - 1;
        return ret;
    };
    mint ans = 1;
    for (int i = 0; i < len; i++) {
        int j = i + k - 1;
        if (j >= len) {
            break;
        }
        // count from the sizes
        {
            int L = get_left(i);
            int R = get_right(j);
            ans += get_count(L, R, k);
        }
        // decrease duplicates
        for (int x = 1; x < 2; x++) {
            // between i and i + x
            if (i + x + k - 1 >= len) {
                break;
            }
            int L = get_left(i + x);
            int R = get_right(j);
            ans -= get_count(L, R, k - x);
        }
    }
    cout << ans << '\n';
    
    return 0;
}