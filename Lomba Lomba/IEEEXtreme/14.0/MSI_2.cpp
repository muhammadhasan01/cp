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

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> a[0][i]; a[0][i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i]; a[1][i]--;
    }
    string ans = "";
    for (int i = 1; i <= n; i++) {
        ans += 'W';
    } 
    for (int i = 1; i <= n; i++) {
        ans += 'B';
    }
    for (int i = 1; i <= 3000; i++) {
        ans += 'W';
        for (int j = 1; j <= 3000; j++) {
            ans += 'B';
        }
        ans += 'W';
    }

    vector<bool> states(n, true);
    auto simulate = [&](const string& s) -> bool {
        for (char cc : s) {
            int id = (cc == 'B');
            vector<bool> v(n);
            for (int i = 0; i < n; i++) {
                if (!states[i]) continue;
                v[a[id][i]] = true;
            }
            states = v;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (states[i]) ++cnt;
        }
        return (cnt == 1);
    };

    if (!simulate(ans)) {
        cout << "Impossible" << '\n';
        return;
    }
    // cout << "Edan" << '\n';
    cout << ans << '\n';
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