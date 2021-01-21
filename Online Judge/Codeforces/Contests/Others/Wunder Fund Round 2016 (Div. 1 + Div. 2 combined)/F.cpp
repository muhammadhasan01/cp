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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s1 += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s2 += b[i];
    }

    auto printAns = [&](int i, int j) -> void {
        cout << j - i << '\n';
        for (int k = i + 1; k <= j; k++) {
            cout << k + 1 << (k == j ? '\n' : ' ');
        }
    };

    auto solve = [&](vector<int>& x, vector<int>& y, bool swap) -> void {
        long long xs = 0, ys = 0;
        int j = -1;
        unordered_map<int, pair<int, int>> mp;
        mp[0] = make_pair(-1, -1);
        for (int i = 0; i < n; i++) {
            xs += x[i];
            while (j + 1 < n && ys + y[j + 1] <= xs) ys += y[++j];
            int diff = (int) (xs - ys);
            if (mp.count(diff) > 0) {
                int px = mp[diff].first;
                int py = mp[diff].second;
                if (swap) {
                    printAns(py, j);
                    printAns(px, i);
                } else {
                    printAns(px, i);
                    printAns(py, j);
                }
                return;
            }
            mp[diff] = make_pair(i, j);
        }
    };

    if (s1 < s2) {
        solve(a, b, false);
    } else {
        solve(b, a, true);
    }

    return 0;
}