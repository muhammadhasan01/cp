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

int n, q;
int a[N], bit[N], ans[N];
vector<pair<int, int>> right_bound[N];

void add(int x) {
    for ( ; x > 0; x -= x & -x) {
        bit[x]++;
    }
}

int get(int x) {
    int ret = 0;
    for ( ; x <= n; x += x & -x)
        ret += bit[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        int l = x + 1, r = n - y;
        right_bound[r].emplace_back(i, l);
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, at = -1;
        if (a[i] >= 0) {
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(mid) >= a[i]) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at != -1) add(at);
        }
        for (auto& e : right_bound[i]) {
            ans[e.first] = get(e.second);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}