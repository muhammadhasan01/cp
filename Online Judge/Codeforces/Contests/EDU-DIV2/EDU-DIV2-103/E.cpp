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

    int n, m, k;
    cin >> n >> m >> k;
    map<string, int> mp;
    vector<string> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]] = i;
    }
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++) {
        string str; cin >> str;
        int idx; cin >> idx;
        for (int j = 0; j < k; j++) {
            if (v[idx][j] == '_') continue;
            if (v[idx][j] != str[j]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
        vector<int> vals;
        for (int mask = 0; mask < (1 << k); mask++) {
            string cur = "";
            for (int j = 0; j < k; j++) {
                cur += (mask & (1 << j) ? str[j] : '_');
            }
            int id = mp[cur];
            if (id == 0) continue;
            vals.emplace_back(id);
        }
        for (int x : vals) {
            if (x == idx) continue;
            adj[idx].emplace_back(x);
            deg[x]++;
        }
    }
    vector<int> vis(n + 1);

    function<bool(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (vis[v] == 0) {
                if (dfs(v)) return true;
            } else if (vis[v] == 1) {
                return true;
            }
        }
        vis[u] = 2;
        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && dfs(i)) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.emplace(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.emplace_back(u);
        for (int v : adj[u]) {
            if (--deg[v] == 0) q.emplace(v);
        }
    }
    cout << "YES" << '\n';
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }

    return 0;
}