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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dif(n + 1, vector<int>(n + 1, -1));
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int lst = -1;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] >= 0) {
                if (lst > 0) {
                    int cur = a[i][lst] - a[i][j];
                    if (dif[lst][j] == -1) {
                        dif[lst][j] = cur;
                        adj[j].emplace_back(lst, cur);
                        adj[lst].emplace_back(j, -cur);
                    } else if (dif[lst][j] != cur) {
                        cout << 0 << '\n';
                        return 0;
                    }
                }
                lst = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        vector<bool> vis(n + 1);
        for (int j = 1; j <= n; j++) {
            if (a[i][j] >= 0) {
                vis[j] = true;
                q.emplace(j);
            }
        }
        while (!q.empty()) {
            int j = q.front();
            q.pop();
            for (auto [k, w] : adj[j]) {
                int val = a[i][j] + w;
                if (val < 0) {
                    cout << 0 << '\n';
                    return 0;
                }
                if (vis[k] && a[i][k] != val) {
                    cout << 0 << '\n';
                    return 0;
                }
                if (!vis[k]) {
                    vis[k] = true;
                    a[i][k] = val;
                    q.emplace(k);
                }
            }
        }
    }
    vector<int> row(n + 1, INT_MAX), col(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] >= 0) {
                row[i] = min(row[i], a[i][j]);
                col[j] = min(col[j], a[i][j]);
            }
        }
    }
    vector<int> candidates;
    for (int i = 1; i <= n; i++) {
        if (row[i] == INT_MAX || col[i] == INT_MAX) {
            cout << -1 << '\n';
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == row[i] && a[i][j] == col[j]) {
                candidates.emplace_back(a[i][j]);
                break;
            }
        }
    }
    int len = (int) candidates.size();
    mint X = 1, Y = 1;
    for (int i = 0; i < len; i++) {
        X *= (candidates[i] + 1);
        Y *= (candidates[i]);
    }
    cout << X - Y << '\n';

    return 0;
}