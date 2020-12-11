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

int n, q;
int a[N];
long long pre[N];
set<long long> st;

void build(int s, int e) {
    long long cur = pre[e] - pre[s - 1];
    st.emplace(cur);
    int midVal = (a[s] + a[e]) / 2;
    int l = s, r = e, at = e;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] <= midVal) {
            l = mid + 1;
            at = mid;
        } else {
            r = mid - 1;
        }
    }
    if (at == e) return;
    build(s, at);
    build(at + 1, e);
}

void init() {
    st.clear();
}

void solve() {
    init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    build(1, n);
    while (q--) {
        long long x;
        cin >> x;
        cout << (st.find(x) != st.end() ? "Yes" : "No") << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}