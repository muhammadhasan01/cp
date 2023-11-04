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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<priority_queue<int>> H(h + 5);
    vector<priority_queue<int>> W(w + 5);
    vector<tuple<int, int, int, int>> points(n);
    for (int i = 0; i < n; i++) {
        auto& [a, r, c, idx] = points[i];
        idx = i;
        cin >> r >> c >> a;
    }
    sort(points.rbegin(), points.rend());
    int aBefore = -1;
    vector<int> ans(n);
    vector<tuple<int, int, int>> vals;
    for (auto& [a, r, c, i] : points) {
        if (aBefore != a) {
            for (auto& [rr, cc, cur] : vals) {
                H[rr].emplace(cur);
                W[cc].emplace(cur);
            }
            vals.clear();
        }
        aBefore = a;
        int cur = 0;
        // horizontal
        {
            if (!H[r].empty()) {
                cur = max(cur, H[r].top() + 1);
            }
        }
        // vertical
        {
            if (!W[c].empty()) {
                cur = max(cur, W[c].top() + 1);
            }
        }
        ans[i] = cur;
        vals.emplace_back(r, c, cur);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}