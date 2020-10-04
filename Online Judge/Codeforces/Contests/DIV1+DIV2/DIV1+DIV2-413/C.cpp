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

int n;
int cost[2];
int res;
vector<pair<int, int>> v[2];

int solve(const vector<pair<int, int>>& a, int m) {
    int len = a.size();
    vector<int> pre(len);
    int ret = 0;
    debug() << imie(a) imie(m);
    for (int i = 0; i < len; i++) {
        pre[i] = a[i].second;
        if (i > 0) pre[i] = max(pre[i], pre[i - 1]);
        int l = 0, r = i - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid].first + a[i].first <= m) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        debug() << imie(i) imie(at);
        if (at == -1) continue;
        ret = max(ret, pre[at] + a[i].second);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int it = 0; it < 2; it++) {
        cin >> cost[it];
    }
    for (int i = 1; i <= n; i++) {
        int b, p; char cc;
        cin >> b >> p >> cc;
        if (cc == 'C') {
            v[0].emplace_back(p, b);
        } else {
            v[1].emplace_back(p, b);
        }
    }
    for (int it = 0; it < 2; it++) {
        sort(v[it].begin(), v[it].end());
    }
    if (!v[0].empty() && !v[1].empty()) {
        vector<int> maksi(2, -1);
        for (int it = 0; it < 2; it++) {
            int maks = -1;
            for (auto e : v[it]) {
                if (e.first > cost[it]) break;
                maks = max(maks, e.second);
            }
            debug() << imie(it) imie(maks);
            maksi[it] = maks;
        }
        bool ok = true;
        for (int it = 0; it < 2; it++) {
            if (maksi[it] == -1) {
                ok = false;
            }
        }
        debug() << imie(maksi);
        if (ok) res = maksi[0] + maksi[1];
    }
    for (int it = 0; it < 2; it++) {
        res = max(res, solve(v[it], cost[it]));
    }
    cout << res << '\n';

    return 0;
}