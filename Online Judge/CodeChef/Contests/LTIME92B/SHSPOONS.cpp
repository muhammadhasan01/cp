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

void solve() {
    int n;
    cin >> n;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        if (i > 0) pq.emplace(vals[i], i + 1);
    }
    long long x = vals[0];
    vector<tuple<int, int, long long>> ans;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.first <= x) {
            ans.emplace_back(cur.second, 1, cur.first);
            x += cur.first;
        } else {
            if (pq.empty()) {
                cout << -1 << '\n';
                return;
            }
            auto aft = pq.top(); pq.pop();
            ans.emplace_back(cur.second, aft.second, cur.first - x);
            aft.first += (cur.first - x);
            ans.emplace_back(cur.second, 1, x);
            x += x;
            pq.emplace(aft.first, aft.second);
        }
    }
    cout << ans.size() << '\n';
    for (auto& e : ans) {
        cout << get<0>(e) << ' ' << get<1>(e) << ' ' << get<2>(e) << '\n';
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