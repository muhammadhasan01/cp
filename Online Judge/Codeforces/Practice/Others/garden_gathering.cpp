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

using LD = long double;
using PLD = pair<long double, long double>;

const LD INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<PLD> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    auto dist = [&](PLD a, PLD b) -> LD {
        LD dx = abs(a.first - b.first);
        LD dy = abs(a.second - b.second);
        return min(dx, dy) * (sqrt(LD(2)) - 1) + max(dx, dy);
    };

    pair<int, int> ans = make_pair(0, 0);

    auto dist_less = [&](pair<int, int> a, pair<int, int> b) -> bool {
        return dist(v[a.first], v[a.second]) < dist(v[b.first], v[b.second]);
    };

    auto check = [&](LD vx, LD vy) -> void {
        LD mini = INF, maxi = -INF;
        int mini_id = 0, maxi_id = 0;
        for (int i = 0; i < n; i++) {
            LD val = v[i].first * vx + v[i].second * vy;
            if (mini > val) {
                mini = val;
                mini_id = i;
            }
            if (maxi < val) {
                maxi = val;
                maxi_id = i;
            }
        }
        pair<int, int> p = make_pair(mini_id, maxi_id);
        if (dist_less(ans, p)) ans = p;
    };

    check(1, sqrt(LD(2)) - 1);
    check(sqrt(LD(2)) - 1, 1);
    check(1, -(sqrt(LD(2)) - 1));
    check(sqrt(LD(2)) - 1, -1);

    cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';

    return 0;
}