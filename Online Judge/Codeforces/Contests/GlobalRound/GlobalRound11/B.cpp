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

const int N = 1e5 + 5;

int tc;
int n, k;
char a[N];
bool pre[N], suf[N];

void solve() {
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 'W')
            res++;
        if (a[i] == 'W' && a[i - 1] == 'W')
            res++; 
    }
    if (res == 0) {
        cout << max(0, 2 * k - 1) << '\n';
        return;
    }
    debug() << imie(res);
    for (int i = 0; i <= n + 1; i++) {
        pre[i] = false, suf[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 'W') continue;
        pre[i] = pre[i - 1];
        if (a[i - 1] == 'W') pre[i] = true;
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 'W') continue;
        suf[i] = suf[i + 1];
        if (a[i + 1] == 'W') suf[i] = true;
    }
    debug() << imie(range(pre + 1, pre + 1 + n));
    debug() << imie(range(suf + 1, suf + 1 + n));
    vector<pair<int, int>> v;
    int resc = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 'L') {
            resc++;
        } else {
            if (resc > 0) {
                int ok = (pre[i - 1] && suf[i - 1]);
                v.emplace_back(1 - ok, resc);
            }
            resc = 0;
        }
    }
    if (resc > 0) {
        v.emplace_back(1, resc);
    }
    sort(v.begin(), v.end());
    debug() << imie(v);
    int len = v.size();
    for (int i = 0; i < len; i++) {
        if (k >= v[i].second) {
            res += 2 * v[i].second;
            if (v[i].first == 0) {
                res++;
            }
            k -= v[i].second;
        } else {
            res += 2 * k;
            break;
        }
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}