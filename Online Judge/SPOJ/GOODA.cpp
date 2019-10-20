#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pli;

const int N = 1e6 + 5;
const long long inf = 1e18;
int n, m, s, e;
int fun[N];
vector<int> g[N], gg[N];
int tin[N], low[N], timer = 0;
int cmp = 0;
bool onstack[N], vis[N];
int comp[N];
long long fcomp[N];
stack<int> st;

void dfs(int u) {
    tin[u] = low[u] = ++timer;
    st.push(u);
    onstack[u] = 1;
    for (auto v : g[u]) {
        if (tin[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onstack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (low[u] == tin[u]) {
        int w = 0;
        ++cmp;
        do {
            w = st.top(); st.pop();
            comp[w] = cmp;
            onstack[w] = false;
        } while (u != w && !st.empty());
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> e;
    for (int i = 1; i <= n; i++) {
        cin >> fun[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (tin[i] == 0) dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        fcomp[comp[i]] += (1LL) * fun[i];
    }
    for (int i = 1; i <= n; i++) {
        int ci = comp[i];
        for (auto e : g[i]) {
            int ce = comp[e];
            if (ci != ce) {
                gg[ci].push_back(ce);
            }
        }
    }
    int cs = comp[s], ce = comp[e];
    priority_queue<pair<long long, int>> pq;
    vector<long long> dp(cmp + 3);
    dp[cs] = fcomp[cs];
    pq.push({dp[cs], cs});
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (auto e : gg[cur]) {
            if (dp[e] < dp[cur] + fcomp[e]) {
                dp[e] = dp[cur] + fcomp[e];
                pq.push({dp[e], e});
            }
        }
    }
    cout << dp[ce] << '\n';

    return 0;
}
