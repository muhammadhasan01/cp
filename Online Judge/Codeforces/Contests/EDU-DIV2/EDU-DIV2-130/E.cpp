#include <bits/stdc++.h>

using namespace std;

template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];
 
    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        save_inv[0] = 0;
        save_inv[1] = 1;
 
        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
 
    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();
 
        if (val < SAVE_INV)
            return save_inv[val];
 
        _m_int product = 1;
        int v = val;
 
        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }
 
        return product * save_inv[v];
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};
 
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
 
extern const int MOD = 998244353;
using mint = _m_int<MOD>;

const int N = 2e2 + 5;
const int INF = 2e9;
 
mint fact[N];
mint invf[N];

mint P(int a, int b) {
    if (a < b) return 0;
    return fact[a] * invf[a - b];
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
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }

    auto getDist = [&](int i, int j) -> int {
        return abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
    };

    vector<int> mins(n, INF);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            mins[i] = min(mins[i], getDist(i, j));
        }
        for (int j = 0; j < n; j++) {
            if (i != j && mins[i] == getDist(i, j)) {
                adj[i].emplace_back(j);
            }
        }
    }
    vector<bool> done(n);

    auto getSet = [&](int s) -> set<int> {
        set<int> st;
        function<void(int)> dfs = [&](int u) {
            if (st.count(u) > 0) {
                return;
            }
            st.emplace(u);
            for (int v : adj[u]) {
                dfs(v);
            }
        };
        dfs(s);
        return st;
    };

    function<void(int)> markDone = [&](int u) {
        done[u] = true;
        for (int v : adj[u]) {
            if (done[v]) {
                continue;
            }
            markDone(v);
        }
    };

    auto checkSet = [&](set<int>& st) -> bool {
        for (int u : st) {
            for (int v : st) {
                if (u == v) {
                    continue;
                }
                int dist = getDist(u, v);
                if (dist != mins[u]) {
                    return false;
                }
            }
        }
        return true;
    };

    vector<vector<int>> comp;

    auto process = [&](int s) -> void {
        if (done[s]) {
            return;
        }
        set<int> st = getSet(s);
        vector<int> cur;
        if (checkSet(st)) {
            cur.emplace_back(1);
            cur.emplace_back((int) st.size());
            markDone(s);
        } else {
            cur.emplace_back(1);
        }
        comp.emplace_back(cur);
    };

    for (int i = 0; i < n; i++) {
        process(i);
    }
    vector<mint> dp(n + 1);
    vector<bool> can(n + 1);
    dp[0] = 1;
    for (vector<int>& colors : comp) {
        vector<mint> ndp(n + 1);
        for (int color : colors) {
            for (int c = 0; c <= n; c++) {
                int nc = c + color;
                if (nc > n) {
                    break;
                }
                ndp[nc] += dp[c];
            }
        }
        dp.swap(ndp);
    }
    mint ans = 0;
    for (int c = 1; c <= n; c++) {
        ans += dp[c] * P(n, c);
    }
    cout << ans << '\n';
    
    return 0;
}