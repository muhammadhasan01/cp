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

const int N = 1e5 + 5;

void solve() {
    vector<int> f(N);
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (f[x] > 0) ans += x;
        f[x]++;
    }
    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);
    
    function<int(int)> fpar = [&](int u) {
        if (par[u] == u) return u;
        return par[u] = fpar(par[u]);
    };

    function<bool(int, int)> merge = [&](int u, int v) {
        int pu = fpar(u);
        int pv = fpar(v);
        if (pu == pv) return false;
        par[pv] = pu;
        return true;
    };
    
    vector<int> val(N);
    {
        int cnt = 0;
        for (int i = 1; i < N; i++) {
            if (f[i] > 0) val[i] = ++cnt;
        }
    }
    for (int i = N - 1; i >= 1; i--) {
        int last = -1;
        for (int j = i; j < N; j += i) {
            if (f[j] == 0) continue;
            int u = val[j];
            if (last == -1) {
                last = u;
                continue;
            }
            if (merge(last, u)) {
                ans += i;
            }
            last = u;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("dream.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case " << T << ": ";
        solve();
    }

    return 0;
}