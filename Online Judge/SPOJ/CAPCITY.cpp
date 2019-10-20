#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
vector<int> g[N], gr[N];
int tin[N], low[N], comp[N], timer = 0, cmp = 0;
vector<int> ans;
bool onstack[N];
stack<int> st;

void dfs(int u) {
    st.push(u); onstack[u] = 1;
    tin[u] = low[u] = ++timer;
    for (auto v : g[u]) {
        if (tin[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onstack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] == low[u]) {
        int w = 0; ++cmp;
        do {
            w = st.top(); st.pop();
            onstack[w] = false;
            comp[w] = cmp;
        } while (w != u && !st.empty());
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (tin[i] == 0) dfs(i);
    }
    
    vector<int> deg(cmp + 3);
    for (int i = 1; i <= n; i++) {
        int ci = comp[i];
        for (auto e : gr[i]) {
            int ce = comp[e];
            if (ci != ce) {
                deg[ce]++;}
        }
    }
    int cnt = 0;
    for (int i = 1; i <= cmp; i++) {
        if (deg[i] == 0) cnt++;
    }

    if (cnt > 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (deg[comp[i]] == 0) ans.push_back(i);
    }

    int len = ans.size();

    cout << len << '\n';
    for (int i = 1; i <= len; i++) {
        cout << ans[i - 1] << (i == len ? '\n' : ' ');
    }

    return 0;
}
