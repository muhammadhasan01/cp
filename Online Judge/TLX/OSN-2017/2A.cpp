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
    
    string s;
    cin >> s;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = make_pair(a[i], i);
    }
    sort(p.begin(), p.end());
    vector<int> at(n);
    for (int i = 0; i < n; i++) {
        at[p[i].second] = i;
    }
    vector<pair<int, int>> ranges;
    for (int i = 0, l = 0, r = 0; i < n; i++) {
        r = max(r, at[i]);
        if (i < r) {
            continue;
        }
        if (r > l) {
            ranges.emplace_back(l, r);
        }
        l = i + 1;
    }
    int ans = 0;
    for (auto [l, r] : ranges) {
        ans += (r - l + 1);
    }
    int m = ranges.size();
    if (k >= m) {
        ans += (k - m);
        cout << ans << '\n';
        return 0;
    }
    vector<int> difs(m - 1);
    for (int i = 1; i < m; i++) {
        difs[i - 1] = ranges[i].first - 1 - ranges[i - 1].second;
    }
    sort(difs.begin(), difs.end());
    for (int i = 0; i < m - k; i++) {
        ans += difs[i];
    }
    cout << ans << '\n';
    
    return 0;
}