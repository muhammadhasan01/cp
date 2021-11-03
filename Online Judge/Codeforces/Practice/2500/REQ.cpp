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

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1, 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] *= val;
    }

    T get(int x) {
        T ret = 1;
        for ( ; x > 0; x -= x & -x)
            ret *= bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

const int INF = 2e9;
const int N = 1e6 + 5;

mint inv[N];
vector<int> primes[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> pp;
    for (int i = 2; i < N; i++) {
        if (!primes[i].empty()) {
            continue;
        }
        pp.emplace_back(i);
        for (int j = i; j < N; j += i) {
            primes[j].emplace_back(i);
        }
    }
    for (int i = 1; i < N; i++) {
        inv[i] = mint(1) / mint(i);
    }
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int>> qr(q);
    for (int i = 0; i < q; i++) {
        auto& [l, r, id] = qr[i];
        cin >> l >> r;
        id = i;
    }
    sort(qr.begin(), qr.end());
    BIT<mint> bit(N);
    vector<int> vis(N, INF);
    vector<queue<int>> st((int) pp.size() + 5);
    auto add_pos = [&](int i) -> void {
        for (int p : primes[a[i]]) {
            int ip = lower_bound(pp.begin(), pp.end(), p) - pp.begin() + 1;
            if (st[ip].empty()) {    
                bit.add(i, p - 1);
                bit.add(i, inv[p]);
            }
            st[ip].emplace(i);
        }
    };
    auto del_pos = [&](int i) -> void {
        bit.add(i, inv[a[i]]);
        for (int p : primes[a[i]]) {
            int ip = lower_bound(pp.begin(), pp.end(), p) - pp.begin() + 1;
            if (st[ip].empty()) {
                continue;
            }
            int id = st[ip].front();
            if (id == i) {
                bit.add(i, inv[p - 1]);
                bit.add(i, p);
                st[ip].pop();
                if (!st[ip].empty()) {
                    int nxt = st[ip].front();
                    bit.add(nxt, p - 1);
                    bit.add(nxt, inv[p]);
                }
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        bit.add(i, a[i]);
        add_pos(i);
    }
    vector<mint> ans(q);
    int curL = 1;
    for (auto& [l, r, id] : qr) {
        while (curL < l) {
            del_pos(curL);
            curL++;
        }
        ans[id] = bit.get(r);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}