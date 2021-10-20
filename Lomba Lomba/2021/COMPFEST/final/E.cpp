// not solved yet
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

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

const int N = 2e5 + 10;

int n, k;
mint a[N];
mint sum[2][N];
mint cnt[2][N];
mint presum[2][N];
mint precnt[2][N];
mint ans;
int sz[N];
bool used[N];
bool try_add;
int maxDist = 0;
int delta;
vector<pair<int, int>> g[N];

void calcSizes(int v, int p) {
    sz[v] = 1;
    for (auto [to, val] : g[v]) if (used[to] && to != p) {
        calcSizes(to, v);
        sz[v] += sz[to];
    }
}

void dfs(int tp, int v, int par, int dist, int col, mint value) {
    if (dist > k) {
        return;
    }
    value += a[v];
    sum[tp][dist] += value * delta;
    cnt[tp][dist] += delta;
    maxDist = max(maxDist, dist);
    if (try_add && dist <= k) {
        ans += value * 2;
    }
    for (auto [to, val] : g[v]) if (used[to] && to != par) {
        dfs(tp, to, v, dist + (col != val), val, value);
    }
}

void dfs2(int tp, int v, int par, int dist, int col, mint value) {
    if (dist > k) {
        return;
    }
    value += a[v];
    if (dist <= k) {
        ans += presum[tp][k - dist];
        ans += precnt[tp][k - dist] * value;
        if (k - dist - 1 >= 0) {
            ans += presum[1 - tp][k - dist - 1];
            ans += precnt[1 - tp][k - dist - 1] * value;
        }
    }
    for (auto [to, val] : g[v]) if (used[to] && to != par) {
        dfs2(tp, to, v, dist + (col != val), val, value);
    }
}

void solve(int v) {
    delta = 1;
    try_add = true;
    maxDist = 0;
    for (auto [to, val] : g[v]) if (used[to]) {
        dfs(val, to, v, 0, val, a[v]);
    }
    try_add = false;
    for (auto [to, val] : g[v]) if (used[to]) {
        delta = -1;
        dfs(val, to, v, 0, val, a[v]);
        for (int it = 0; it < 2; it++) {
            for (int i = 0; i <= maxDist + 2; i++) {
                presum[it][i] = sum[it][i];
                precnt[it][i] = cnt[it][i];
                if (i > 0) {
                    presum[it][i] += presum[it][i - 1];
                    precnt[it][i] += precnt[it][i - 1];
                }
            }
        }
        dfs2(val, to, v, 0, val, 0);
        delta = 1;
        dfs(val, to, v, 0, val, a[v]);
    }
    for (int tp = 0; tp < 2; tp++) {
        for (int i = 0; i <= maxDist + 2; i++) {
            sum[tp][i] = 0;
            cnt[tp][i] = 0;
        }
    }
}

void cd(int v, int p) {
    calcSizes(v, -1);
    int tot = sz[v];
    bool ok = false;
    int pp = -1;
    while (!ok) {
        ok = true;
        for (auto [to, val] : g[v]) if (used[to] && to != pp && sz[to] * 2 > tot) {
            pp = v;
            v = to;
            ok = false;
            break;
        }
    }
    solve(v);
    used[v] = false;
    for (auto [to, val] : g[v]) if (used[to]) {
        cd(to, v);
    }
}

void solve() {
    forn(i, n) used[i] = true;
    cd(0, -1);
    long long res = (ans / 2).x;
    out(res, '\n');
}

void readTest() {
    in(n), in(k);
    forn(i, n) {
        int x;
        in(x);
        a[i] = x;        
    }
    forn(i, n) {
        ans += a[i] * 2;
    }
    forn(i, n - 1) {
        int from, to, val;
        in(from), in(to), in(val);
        --from, --to;
        g[from].eb(to, val);
        g[to].eb(from, val);
    }
}

int main() {
    readTest();
    solve();
    return 0;
}