#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

const int N = 1e6 + 5;

int n, k;
int ans[N];
int a[N], b[N];

typedef int t_data;

const t_data TERM = 0;

struct Segtree {
    vector<t_data> t;
    Segtree() {
        t.assign(4 * N, 0);
    }

    t_data combine(const t_data& x, const t_data& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    t_data get(int v, int s, int e, t_data l, t_data r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        t_data p1 = get(v << 1, s, mid, l, r);
        t_data p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
} sgt;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] *= 100;
    }
    sgt.build(1, 1, n);
    vector<pair<int, int>> v(n);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        v[i - 1] = make_pair(b[i], i);
    }
    sort(v.begin(), v.end());
    debug() << imie(v);
    set<int> st = {n + 1};
    for (int i = 0; i < n; i++) {
        int L = v[i].second;
        int R = *st.upper_bound(L);
        ans[L] = min(sgt.get(1, 1, n, L, R - 1), v[i].first);
        ans[L] = max(ans[L], ans[R]);
        st.emplace(L);
        debug() << imie(L) imie(R) imie(ans[L]);
    }
    debug() << imie(range(ans + 1, ans + 1 + n));
    sort(ans + 1, ans + 1 + n);
    long double answer = 0;
    long double F = (long double) k / n;
    for (int i = 1; i <= n; i++) {
        answer += (long double) ans[i] * F;
        if (n > i) F = (F * (long double) (n - k - i + 1) / (n - i));
    }
    cout << fixed << setprecision(12) << answer << '\n';

    return 0;
}