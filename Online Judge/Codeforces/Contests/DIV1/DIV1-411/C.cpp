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

const int N = 3e5 + 5;

int n, m;
int s[N];
int ans = 1, res[N];
vector<int> st[N], adj[N];

void dfs(int u, int p) {
    sort(st[u].begin(), st[u].end(), [&](int x, int y) {
        return res[x] < res[y];
    });
    int col = ans, len = s[u] - 1;
    for (int x : st[u]) {
        if (res[x]) break;
        while (len >= 0 && col == res[st[u][len]]) {
            col--, len--;
        }
        res[x] = col--;
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ans = max(ans, s[i]);
        st[i].resize(s[i]);
        for (int j = 0; j < s[i]; j++) {
            cin >> st[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    cout << ans << '\n';
    for (int i = 1; i <= m; i++) {
        cout << max(1, res[i]) << (i == m ? '\n' : ' ');
    }

    return 0;
}