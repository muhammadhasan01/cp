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
    int n, m;
    cin >> n >> m;
    vector<char> s(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<int> vals(n + 5);
    vector<int> mini(n + 5), maxi(n + 5);
    {
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '+')    
                cur++;
            else
                cur--;
            vals[i] = cur;
            mini[i] = min(mini[i - 1], cur);
            maxi[i] = max(maxi[i - 1], cur);
        }
    }
    vector<int> suf_min(n + 5), suf_max(n + 5);
    {
        suf_max[n] = suf_min[n] = vals[n];
        for (int i = n - 1; i >= 1; i--) {
            suf_max[i] = max(suf_max[i + 1], vals[i]);
            suf_min[i] = min(suf_min[i + 1], vals[i]);
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (r == n) {
            cout << maxi[l - 1] - mini[l - 1] + 1 << '\n';
            continue;
        }
        int curMaxi = maxi[l - 1];
        int curMini = mini[l - 1];
        int maxPlus = suf_max[r + 1] - vals[r];
        int minPlus = suf_min[r + 1] - vals[r];
        curMaxi = max(curMaxi, vals[l - 1] + maxPlus);
        curMini = min(curMini, vals[l - 1] + minPlus);
        cout << curMaxi - curMini + 1 << '\n';
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