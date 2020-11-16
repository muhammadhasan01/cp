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

const int N = 3e5 + 5;
const int INF = 1e7;

int n;
int b[N];
int t[4 * N];
deque<int> pos[N];

void init() {
    for (int i = 1; i <= 4 * n; i++) {
        t[i] = INF;
        if (i <= n) pos[i].clear();
    }
}

void update(int v, int s, int e, int pos, int val) {
    if (s == e && s == pos) {
        t[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
        update(v << 1, s, mid, pos, val);
    else
        update(v << 1 | 1, mid + 1, e, pos, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r)
        return INF;
    if (l <= s && e <= r)
        return t[v];
    int mid = (s + e) >> 1;
    return min(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (pos[i].empty()) continue;
        update(1, 1, n, i, pos[i].front());
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int x = b[i];
        if (pos[x].empty()) {
            ok = false;
            break;
        }
        int cur = pos[x].front();
        pos[x].pop_front();
        if (get(1, 1, n, 1, x) < cur) {
            ok = false;
            break;
        }
        int val = (pos[x].empty() ? INF : pos[x].front());
        update(1, 1, n, x, val);
    }
    cout << (ok ? "YES" : "NO") << '\n';
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