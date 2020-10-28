#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

const int INF = 2e9;

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int lis(vector<int> const& a, int bl, int br) {
    int n = a.size();
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        if (a[i] < bl || a[i] > br) continue;
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return n - ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] -= i;
    }
    vector<int> b(k);
    vector<bool> bad(n);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        bad[--b[i]] = 1;
    }
    for (int i = 0; i < k - 1; i++) {
        if (v[b[i + 1]] < v[b[i]]) {
            dismiss();
        }
    }
    vector<int> val;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        val.emplace_back(v[i]);
        if (!bad[i]) continue;
        {
            int bl = -INF, br = v[i];
            int pos = i - (int) val.size() + 1;
            if (bad[pos]) bl = v[pos];
            ans += lis(val, bl, br);
        }
        val.clear();
        val.emplace_back(v[i]);
    }
    {
        int bl = -INF, br = INF - 5;
        int pos = n - (int) val.size();
        if (bad[pos]) bl = v[pos];
        ans += lis(val, bl, br);
    }
    cout << ans << "\n";

    return 0;
}