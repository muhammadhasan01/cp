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

const int N = 105;

int n;
pair<int, int> a[N];

void solve() {
    cin >> n;
    vector<bool> vis(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        vis[a[i].first] =  1;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    vector<int> ans(2 * n + 1);
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        int id = a[i].second;
        ans[2 * id - 1] = a[i].first;
    }
    for (int i = 2; i <= 2 * n; i += 2) {
        for (int j = ans[i - 1] + 1; j <= 2 * n; j++) {
            if (vis[j]) continue;
            vis[j] = 1;
            ans[i] = j;
            break;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << (i == 2 * n ? '\n' : ' ');
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