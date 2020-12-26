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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<pair<int, int>> w;
    int cur = v[0], cnt = 0;    
    for (int i = 0; i < n; i++) {
        if (cur == v[i]) {
            ++cnt;
        } else {
            w.emplace_back(cur, cnt);
            cur = v[i];
            cnt = 1;
        }
    }
    w.emplace_back(cur, cnt);
    int len = w.size();
    vector<bool> ok(len);
    int answer = 0;
    for (int i = 1; i < len - 1; i++) {
        if (w[i].second > 1) continue;
        if (ok[i - 1] || ok[i + 1]) continue;
        if (w[i - 1].first != w[i + 1].first) continue;
        if (w[i - 1].second % 2 == 0 || w[i + 1].second % 2 == 0) continue;
        if ((w[i - 1].second + w[i + 1].second) & 1) continue;
        ok[i - 1] = ok[i + 1] = ok[i] = 1;
        ++answer;
    }
    for (int i = 0; i < len; i++) {
        if (w[i].second % 2 == 1 && !ok[i]) ++answer;
    }
    cout << answer << '\n';
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