#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, k;
set<int> g[N];
pair<int, int> p[N];
set<pair<int, int>> st;
bool inSet[N];
int ans[N], deg[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++, deg[v]++;
        p[i] = {u, v};
    }
    for (int i = 1; i <= n; i++) {
        st.insert({deg[i], i});
        inSet[i] = true;
    }
    for (int i = m; i >= 1; i--) {
        while (!st.empty() && st.begin()->first < k) {
            int x = st.begin()->second;
            for (auto y : g[x]) {
                if (inSet[y]) {
                    st.erase({deg[y], y});
                    deg[y]--;
                    st.insert({deg[y], y});
                }
            }
            inSet[x] = false;
            st.erase({deg[x], x});
        }
        ans[i] = st.size();
        int u = p[i].first;
        int v = p[i].second;
        g[u].erase(v);
        g[v].erase(u);
        if (!inSet[u] || !inSet[v]) continue;
        st.erase({deg[u], u});
        deg[u]--;
        st.insert({deg[u], u});
        st.erase({deg[v], v});
        deg[v]--;
        st.insert({deg[v], v});
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}