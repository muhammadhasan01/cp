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

const pair<mint, mint> DEFAULT = {1, 0};

struct SegtreeLazy {
    vector<mint> t;
    vector<mint> pre;
    vector<pair<mint, mint>> lazy;
    SegtreeLazy(vector<mint>& t_pre) {
        int n = (int) t_pre.size();
        t.assign(4 * n, 0);
        lazy.assign(4 * n, DEFAULT);
        pre.assign(t_pre.begin(), t_pre.end());
    }

    void updateVal(mint& x, int s, int e, pair<mint, mint>& y) {
        mint cnt = pre[e] - (s == 0 ? 0 : pre[s - 1]);
        x = (x * y.first + y.second * cnt);
    }

    void updateLazy(pair<mint, mint>& x, pair<mint, mint>& y) {
        // f(p) = a * p + b
        // f((a * p + b)) = c * (a * p + b) + d = c * a * p + c * b + d
        x = {y.first * x.first, y.first * x.second + y.second};
    }

    void push(int v, int s, int e) {
        if (lazy[v] == DEFAULT) {
            return;
        }
        int mid = (s + e) >> 1;
        updateVal(t[v << 1], s, mid, lazy[v]);
        updateVal(t[v << 1 | 1], mid + 1, e, lazy[v]);
        updateLazy(lazy[v << 1], lazy[v]);
        updateLazy(lazy[v << 1 | 1], lazy[v]);
        lazy[v] = DEFAULT;
    }

    void update(int v, int s, int e, int l, int r, pair<mint, mint> x) {
        if (l > r) return;
        if (l == s && e == r) {
            updateVal(t[v], s, e, x);
            updateLazy(lazy[v], x);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), x);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, x);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    mint get(int v, int s, int e, int l, int r) {
        if (l > r)
            return 0;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        return get(v << 1, s, mid, l, min(r, mid)) + get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> nums = {1};
    for (int i = 0; i < n; i++) {
        for (int dif = 0; dif <= 1; dif++) {
            nums.emplace_back(a[i] + dif);
        }
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int len = (int) nums.size();
    vector<mint> pref(len);
    pref[0] = nums[0];
    for (int i = 1; i < len; i++) {
        pref[i] = pref[i - 1] + (nums[i] - nums[i - 1]);
    }
    
    auto getId = [&](int x) -> int {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    };

    SegtreeLazy sgt(pref);
    sgt.update(1, 0, len - 1, 0, getId(a[0]), {0, 1});
    for (int i = 1; i < n; i++) {
        mint sum = sgt.get(1, 0, len - 1, 0, len - 1);
        sgt.update(1, 0, len - 1, getId(a[i] + 1), len - 1, {0, 0});
        sgt.update(1, 0, len - 1, 0, getId(a[i]), {-1, sum});
    }
    cout << sgt.get(1, 0, len - 1, 0, len - 1) << '\n';
    
    return 0;
}