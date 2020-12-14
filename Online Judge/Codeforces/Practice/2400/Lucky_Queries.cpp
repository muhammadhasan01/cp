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

const int N = 1e6 + 5;

struct st {
    // L -> 4, R -> 7
    int L, R, LR, RL;
};

int n, m;
char str[N];
st t[4 * N];
int lazy[4 * N];

st merge(st a, st b) {
    st ret;
    ret.L = a.L + b.L;
    ret.R = a.R + b.R;
    ret.LR = max(max(a.LR, a.L) + b.R, a.L + max(b.LR, b.R));
    ret.RL = max(max(a.RL, a.R) + b.L, a.R + max(b.RL, b.L));
    return ret;
}

void upd(st& a) {
    swap(a.L, a.R);
    swap(a.LR, a.RL);
}

void push(int v, int s, int e) {
    if (s == e || lazy[v] == 0) return;
    lazy[v << 1] ^= 1;
    lazy[v << 1 | 1] ^= 1;
    upd(t[v << 1]);
    upd(t[v << 1 | 1]);
    lazy[v] = 0;
}

void build(int v, int s, int e) {
    if (s == e) {
        if (str[s] == '4') {
            t[v] = {1, 0, 1, 1};
        } else {
            t[v] = {0, 1, 1, 1};
        }
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

void updateRange(int v, int s, int e, int l, int r) {
    if (l > r) return;
    if (l == s && e == r) {
        upd(t[v]);
        lazy[v] ^= 1;
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid));
    updateRange(v << 1 | 1, mid + 1, e, max(mid + 1, l), r);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

st get(int v, int s, int e, int l, int r) {
    if (l > r) return {0, 0, 0, 0};
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    return merge(get(v << 1, s, mid, l, min(r, mid)),
                 get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
    }
    build(1, 1, n);
    while (m--) {
        string qr;
        cin >> qr;
        if (qr[0] == 'c') {
            st res = get(1, 1, n, 1, n);
            cout << max(res.LR, max(res.L, res.R)) << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            updateRange(1, 1, n, l, r);
        }
    }

    return 0;
}