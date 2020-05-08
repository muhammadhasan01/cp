#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<int> g[N], rg[N];
int c[N];
int deg[N], rdeg[N];
bool ans[N];
int dp[N], pd[N];

bool dfs(int u) {
    c[u] = 1;
    for (auto v : g[u]) {
        if (c[v] == 0) {
            if (dfs(v))
                return true;
        } else if (c[v] == 1) {
            return true;
        }
    }
    c[u] = 2;
    return false;
}

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    iota(dp + 1, dp + 1 + n, 1);
    iota(pd + 1, pd + 1 + n, 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
        rg[x].push_back(y);
        deg[x]++;
        rdeg[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (dfs(i))
            dismiss();
    }
    queue<int> q, rq;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
        if (rdeg[i] == 0) {
            rq.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            dp[v] = min(dp[v], dp[u]);
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }
    while (!rq.empty()) {
        int u = rq.front();
        rq.pop();
        for (auto v : rg[u]) {
            pd[v] = min(pd[v], pd[u]);
            if (--rdeg[v] == 0) {
                rq.push(v);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (pd[i] == dp[i] && dp[i] == i) {
            ans[i] = true;
            res++;
        }
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] ? 'A' : 'E');
    }
    cout << '\n';

    return 0;
}