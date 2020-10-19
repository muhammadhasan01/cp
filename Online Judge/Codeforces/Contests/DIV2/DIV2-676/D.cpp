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

const int N = 6;
const pair<int, int> p[] = {{1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, 0}};

long long x, y;
long long c[N], dp[N];

long long solveOne() {
    long long ret = min(x, y) * dp[0];
    if (x >= y) {
        ret += dp[5] * (x - y);
    } else {
        ret += dp[1] * (y - x);
    }
    return ret;
}

long long solveTwo() {
    long long ret = x * dp[5] - y * dp[4];
    return ret;
}

void solve() {
    cin >> x >> y;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        dp[i] = c[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (p[i].first + p[j].first != p[k].first) continue;
                if (p[i].second + p[j].second != p[k].second) continue;
                dp[k] = min(dp[k], c[i] + c[j]);
            }
        }
    }
    long long ans;
    if (x >= 0 && y >= 0) {
        ans = solveOne();
    } else if (x <= 0 && y <= 0) {
        x = -x, y = -y;
        for (int i = 0; i < 3; i++) {
            swap(dp[i], dp[i + 3]);
        }
        ans = solveOne();
    } else if (x >= 0 && y <= 0) {
        ans = solveTwo();
    } else if (x <= 0 && y >= 0) {
        x = -x, y = -y;
        for (int i = 0; i < 3; i++) {
            swap(dp[i], dp[i + 3]);
        }
        ans = solveTwo();
    }
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