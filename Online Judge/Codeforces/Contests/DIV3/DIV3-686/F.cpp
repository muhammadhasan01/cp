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

const int N = 2e5 + 5;
const int INF = 2e9;

int n;
int a[N];
int pre[N], suf[N];

struct Segtree {
    vector<int> t;
    Segtree() {
        t.assign(4 * N, 0);
    }

    int combine(const int& x, const int& y) {
        return (x < y ? x : y);
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

    void update(int v, int s, int e, int pos, int val) {
        if (s == e && s == pos) {
            t[v] += val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    int get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return INF;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        int p1 = get(v << 1, s, mid, l, r);
        int p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
} sgt;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sgt.build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        pre[i] = max(a[i], pre[i - 1]);
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suf[i] = max(a[i], suf[i + 1]);
    }
    for (int i = 2; i <= n - 1; i++) {
        int atL = -1;
        {
            int l = 1, r = i - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[mid] <= a[i]) {
                    l = mid + 1;
                    atL = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        if (atL == -1 || pre[atL] != a[i]) continue;
        int atR = -1;
        {
            int l = i + 1, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (suf[mid] <= a[i]) {
                    r = mid - 1;
                    atR = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        if (atR == -1 || suf[atR] != a[i]) continue;
        int query = sgt.get(1, 1, n, atL + 1, atR - 1);
        if (query != a[i]) continue;
        cout << "YES" << '\n';
        cout << atL << " " << atR - atL - 1 << " " << n - atR + 1 << '\n';
        return;
    }
    cout << "NO" << '\n';
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