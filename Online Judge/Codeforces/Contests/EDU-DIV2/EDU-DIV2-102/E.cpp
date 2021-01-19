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

const long long INF = 1e18;
const int N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
long long ans[N][2][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ans[i][j][k] = INF;
            }
        }
    }
    ans[1][0][0] = 0LL;
    set<pair<long long, tuple<int, int, int>>> st;
    st.insert({0, {1, 0, 0}});
    while (!st.empty()) {
        int u, mx, mn;
        tie(u, mx, mn) = st.begin()->second;
        st.erase(st.begin());
        for (auto& e : adj[u]) {
            int v, w;
            tie(v, w) = e;
            for (int i = 0; i <= 1 - mx; i++) {
                for (int j = 0; j <= 1 - mn; j++) {
                    if (ans[v][mx | i][mn | j] > ans[u][mx][mn] + (1LL) * (1 - i + j) * w) {
                        auto it = st.find({ans[v][mx | i][mn | j], {v, mx | i, mn | j}});
                        if (it != st.end())
                            st.erase(it);
                        ans[v][mx | i][mn | j] = ans[u][mx][mn] + (1LL) * (1 - i + j) * w;
                        st.insert({ans[v][mx | i][mn | j], {v, mx | i, mn | j}});
                    }
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << ans[i][1][1] << (i == n ? '\n' : ' ');
    }

    return 0;
}