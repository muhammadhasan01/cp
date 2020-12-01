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

const long long INF = 1e18;

void solve() {
    vector<pair<int, int>> p(4);
    for (int i = 0; i < 4; i++) {
        cin >> p[i].first >> p[i].second;
    }
    long long ans = INF;
    sort(p.begin(), p.end());
    do {
        vector<int> cand = {0};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cand.emplace_back(p[2 + j].first - p[i].first);
                cand.emplace_back(p[2 * j + 1].second - p[2 * i].second);
            }
        }
        for (auto d : cand) {
            if (d < 0) continue;
            long long cur = 0;
            vector<int> x(4), y(4);
            for (int i = 0; i < 4; i++) {
                tie(x[i], y[i]) = p[i];
            }
            x[2] -= d, x[3] -= d;
            y[1] -= d, y[3] -= d;
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            long long res = 0;
            for (int i = 0; i < 4; i++) {
                res += abs(x[i] - x[1]);
                res += abs(y[i] - y[1]);
            }
            ans = min(ans, res);
        }
    } while (next_permutation(p.begin(), p.end()));
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