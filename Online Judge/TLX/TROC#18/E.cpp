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

const int N = 4e5 + 5;
const int TERM = 0;

struct SegtreeLazy {
    vector<int> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }

    int combine(const int& x, const int& y) {
        return (x ^ y);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        t[v << 1] ^= lazy[v];
        t[v << 1 | 1] ^= lazy[v];
        lazy[v << 1] ^= lazy[v];
        lazy[v << 1 | 1] ^= lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, int val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] ^= val;
            lazy[v] ^= val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    int get(int v, int s, int e, int l, int r) {
        if (l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        int p1 = get(v << 1, s, mid, l, min(r, mid));
        int p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
} sgt[2];

int n, q;
int depth[N];
vector<int> adj[N];
int tin[N][2], tout[N][2];
int len[2];

void dfs(int u, int p, int h = 0) {
    depth[u] = h;
    tin[u][h] = ++len[h];
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, 1 - h);
    }
    tout[u][h] = ++len[h];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        in(u), in(v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    in(q);
    while (q--) {
        int tp;
        in(tp);
        if (tp == 1) {
            int u, x;
            in(u), in(x);
            int parity = depth[u];
            sgt[parity].update(1, 1, len[parity], tin[u][parity], tout[u][parity], x);
        } else if (tp == 2) {
            int u;
            in(u);
            int parity = depth[u];
            int ans = sgt[parity].get(1, 1, len[parity], tin[u][parity], tin[u][parity]);
            out(ans, '\n');
        }
    }

    return 0;
}