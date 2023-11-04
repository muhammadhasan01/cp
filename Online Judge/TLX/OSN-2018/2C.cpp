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
 
extern const int MOD = 1e9 + 7;
using mint = _m_int<MOD>;

template<typename T>
struct SparseTable {
    int n;
    vector<vector<T>> dp;
    vector<int> prec;

    SparseTable(vector<T>& a) {
        n = a.size();
        int len = 1;
        int k = 0;
        while (len <= 2 * n) {
            len <<= 1;
            ++k;
        }
        dp.assign(len, vector<T>(k, 0));
        prec.assign(len, 0);
        for (int i = 2; i < 2 * n; i++) {
            prec[i] = prec[i >> 1] + 1;
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = a[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = combine(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T combine(const T& a, const T& b) {
        return __gcd(a, b);
    }

    T query(int l, int r) {
        int k = prec[r - l + 1];
        return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> str;
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    SparseTable<int> sp(a);
    vector<mint> dp(n + 1);
    vector<mint> ways(n + 1, 1);
    vector<mint> pre(n + 1);
    vector<mint> sum(n + 1);
    for (int i = 0; i <= n; i++) {
        pre[i] = (i - 1 >= 0 ? pre[i - 1] : 0) + ways[i];
    }
    vector<vector<tuple<int, int, int>>> ranges(n + 1);
    for (int i = 1; i <= n; i++) {
        int lft = i;
        while (lft >= 1) {
            int cur = sp.query(lft, i);
            int l = 1, r = lft, at = lft;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sp.query(mid, i) == cur) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            ranges[i].emplace_back(cur, lft, at);
            lft = at - 1;
        }
    }
    for (int j = 1; j <= k; j++) {
        vector<mint> ndp(n + 1);
        vector<mint> nways(n + 1);
        vector<mint> npre(n + 1);
        vector<mint> nsum(n + 1);
        for (int i = j; i <= n - k + j; i++) {
            nways[i] = pre[i - 1] + nways[i - 1];
            ndp[i] += ndp[i - 1];
            for (auto [cur, lft, at] : ranges[i]) {
                if (lft < j) {
                    break;
                }
                ndp[i] += mint(cur) * (pre[lft - 1] - (at - 2 >= 0 ? pre[at - 2] : 0));
                ndp[i] += (sum[lft - 1] - (at - 2 >= 0 ? sum[at - 2] : 0));
            } 
            npre[i] = nways[i] + npre[i - 1];
            nsum[i] = ndp[i] + nsum[i - 1];
        }
        dp.swap(ndp);
        pre.swap(npre);
        ways.swap(nways);
        sum.swap(nsum);
    }
    cout << dp[n] << '\n';

    return 0;
}