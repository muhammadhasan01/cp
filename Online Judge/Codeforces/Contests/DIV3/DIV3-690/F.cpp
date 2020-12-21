// Kamal Farras Imba Ane Cupu
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

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        nums.emplace_back(v[i].first);
        nums.emplace_back(v[i].second);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());

    auto getId = [&](int x) -> int {
        return (int) (lower_bound(nums.begin(), nums.end(), x) - nums.begin()) + 1;
    };

    for (int i = 0; i < n; i++) {
        v[i].first = getId(v[i].first);
        v[i].second = getId(v[i].second);
    }
    sort(v.begin(), v.end());
    vector<int> pre(2 * n + 5), suf(2 * n + 5);
    for (auto& e : v) {
        pre[e.second]++;
        suf[e.first]++;
    }
    for (int i = 1; i < 2 * n + 5; i++) {
        pre[i] += pre[i - 1];
    }
    for (int i = 2 * n + 3; i >= 0; i--) {
        suf[i] += suf[i + 1];
    }
    int ans = INF;
    for (auto& e : v) {
        int cur = pre[e.first - 1] + suf[e.second + 1];
        ans = min(ans, cur);
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