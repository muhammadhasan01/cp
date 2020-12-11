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

const int N = 1e5 + 5;

int n, m;
long long t[4 * N];
int color[4 * N];
long long lazy[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        color[v] = s;
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
}

void push(int v, int s, int e) {
    if (s == e || lazy[v] == 0) return;
    int mid = (s + e) >> 1;
    t[v << 1] += lazy[v] * (mid - s + 1);
    color[v << 1] = color[v];
    lazy[v << 1] += lazy[v];
    t[v << 1 | 1] += lazy[v] * (e - mid);
    lazy[v << 1 | 1] += lazy[v];
    color[v << 1 | 1] = color[v];
    lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r, int col) {
    if (l > r) return;
    if (l == s && e == r) {
        if (color[v] == 0) {
            int mid = (s + e) >> 1;
            updateRange(v << 1, s, mid, l, min(r, mid), col);
            updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, col);
            t[v] = t[v << 1] + t[v << 1 | 1];
        } else {
            t[v] += (1LL) * (e - s + 1) * abs(color[v] - col);
            lazy[v] += abs(color[v] - col);
        }
        color[v] = col;
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), col);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, col);
    t[v] = t[v << 1] + t[v << 1 | 1];
    color[v] = (color[v << 1] == color[v << 1 | 1] ? color[v << 1] : 0);
}

long long getRange(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r)
        return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    return getRange(v << 1, s, mid, l, min(r, mid)) + getRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            updateRange(1, 1, n, l, r, x);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            cout << getRange(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}