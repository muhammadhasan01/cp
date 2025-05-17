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

const int N = 3e5 + 5;
const int B = 550;
 
mint fact[N];
mint invf[N];
 
mint C(int a, int b) {
    if (a < b) return 0;
    return fact[a] * invf[b] * invf[a - b];
}
 
void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
    }
    invf[N - 1] = fact[N - 1].inv();
    for (int i = N - 1; i > 0; i--) {
        invf[i - 1] = invf[i] * i;
    }
}

struct Query {
    int l, r, x, id;
};

bool cmp(const Query &a, const Query &b) {
    int bl1 = a.l / B, bl2 = b.l / B;
    if (bl1 != bl2) return bl1 < bl2;
    int br1 = a.r / B, br2 = b.r / B;
    if (br1 != br2) return (bl1 & 1) ? br1 > br2 : br1 < br2;
    return (br1 & 1) ? a.x > b.x : a.x < b.x;
}

int cnt[N], a[N], n, q;
int curL = 1, curR = 0, curX = 1, len = 0;
mint prod = 1;

void add_val(int v) {
    prod *= invf[cnt[v]];
    len += cnt[v];
}

void remove_val(int v) {
    prod *= fact[cnt[v]];
    len -= cnt[v];
}

void add(int i) {
    int v = a[i];
    if (v < curX) {
        prod *= fact[cnt[v]];
        cnt[v]++;
        prod *= invf[cnt[v]];
        len++;
    } else {
        cnt[v]++;
    }
}

void remove(int i) {
    int v = a[i];
    if (v < curX) {
        prod *= fact[cnt[v]];
        cnt[v]--;
        prod *= invf[cnt[v]];
        len--;
    } else {
        cnt[v]--;
    }
}

void increase_X() {
    if (cnt[curX] > 0) add_val(curX);
    curX++;
}

void decrease_X() {
    curX--;
    if (cnt[curX] > 0) remove_val(curX);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].x;
        queries[i].id = i;
    }

    sort(queries.begin(), queries.end(), cmp);
    vector<mint> res(q);

    for (auto [l, r, x, id] : queries) {
        while (curL > l) add(--curL);
        while (curR < r) add(++curR);
        while (curL < l) remove(curL++);
        while (curR > r) remove(curR--);
        while (curX < x) increase_X();
        while (curX > x) decrease_X();

        res[id] = fact[len] * prod;
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}
