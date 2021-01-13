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

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        radj[v].emplace_back(u);
    }
    vector<int> d(n, INF);
    {
        queue<int> q;
        q.emplace(0);
        d[0] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (d[v] > d[u] + 1) {
                    d[v] = d[u] + 1;
                    q.emplace(v);
                }
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = d[i];
    }
    {
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            st.emplace(d[i], i);
        }
        while (!st.empty()) {
            auto cur = *st.begin();
            st.erase(st.begin());
            int res, u;
            tie(res, u) = cur;
            for (int v : radj[u]) {
                if (d[v] >= d[u] && d[u] < ans[v]) {
                    st.erase(make_pair(ans[v], v));
                    ans[v] = d[u];
                    st.emplace(ans[v], v);
                } else if (d[v] < d[u] && res < ans[v]) {
                    st.erase(make_pair(ans[v], v));
                    ans[v] = res;
                    st.emplace(ans[v], v);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
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