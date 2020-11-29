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

using pll = pair<long long, long long>;

struct vertex {
    pll val;
    vertex *l, *r;
    vertex(pll val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(make_pair(0LL, 0LL)), l(l), r(r) {
        if (l) {
            val.first += l->val.first;
            val.second += l->val.second;
        }
        if (r) {
            val.first += r->val.first;
            val.second += r->val.second;
        }
    }
};
typedef vertex* pvertex;

const int N = 2e5 + 5;

int n, q;
int cnt[N];
pvertex psegtree[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(make_pair(0LL, 0LL));
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos, pll val) {
    if (s == e && s == pos)
        return new vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos, val));
}

int cL, cR;
pll getQuery(pvertex v, pvertex w, int s, int e) {
    if (e < cL || s > cR || cL > cR) return make_pair(0, 0);
    if (cL <= s && e <= cR)
        return make_pair(w->val.first - v->val.first, w->val.second - v->val.second);
    int mid = (s + e) >> 1;
    pll p1 = getQuery(v->l, w->l, s, mid);
    pll p2 = getQuery(v->r, w->r, mid + 1, e);
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n);
    psegtree[0] = build(1, N);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; in(x);
        a[i] = x;
        cnt[x]++;
        long long res = (1LL) * x * cnt[x];
        psegtree[i] = update(psegtree[i - 1], 1, N, x, make_pair(cnt[x], res));
    }

    auto can = [&](int L, int R, int A, int B, int S, int len) -> bool {
        vector<int> euy;
        for (int i = L; i <= R; i++) {
            if (A <= a[i] && a[i] <= B) {
                euy.emplace_back(a[i]);
            }
        }
        if (len > (int) euy.size()) return false;
        sort(euy.rbegin(), euy.rend());
        long long sum = 0;
        for (int i = 0; i < len; i++) {
            sum += euy[i];
        }
        return (sum >= (1LL) * len * S);
    };

    in(q);
    while (q--) {
        debug() << imie(q);
        int L, R, A, B, S;
        in(L), in(R), in(A), in(B), in(S);
        int l = 1, r = R - L + 1, at = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(L, R, A, B, S, mid)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        out(at, '\n');
    }

    return 0;
}