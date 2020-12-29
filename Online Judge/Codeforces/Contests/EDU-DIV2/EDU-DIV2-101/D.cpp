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

    vector<pair<int, int>> answer;

    if (n < 50) {
        for (int i = 3; i < n; i++) {
            if (i == 2) continue;
            answer.emplace_back(i, n);
        }
        for (int i = 0; i < 6; i++) {
            answer.emplace_back(n, 2);
        }
    } else {
        int k = sqrt(n) + 10;
        for (int i = 4; i < n; i++) {
            if (i == k) continue;
            answer.emplace_back(i, n);
        }
        int cur = n;
        while (cur > 1) {
            cur = (cur + k - 1) / k;
            answer.emplace_back(n, k);
        }
        int x = k;
        while (x > 1) {
            x = (x + 2) / 3;
            answer.emplace_back(k, 3);
        }
        for (int it = 0; it < 2; it++) answer.emplace_back(3, 2);
    }
    
    cout << answer.size() << '\n';
    for (auto& e : answer) {
        cout << e.first << ' ' << e.second << '\n';
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