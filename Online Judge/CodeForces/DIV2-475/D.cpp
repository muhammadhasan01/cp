#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, sz[N], par[N];
vector<int> g[N], ans;
stack<int> s;
bitset<N> vis;

void add(int u, int p) {
    s.push(u);
    par[u] = p;
    for (auto v : g[u]) {
        if (v == p) continue;
        add(v, u);
    }
}

void dfs(int u) {
    vis[u] = 1;
    ans.push_back(u);
    for (auto v : g[u]) {
        sz[v]--;
        if (par[u] == v) continue;
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            sz[i]++, sz[x]++;
            g[i].push_back(x);
            g[x].push_back(i);
        }
    }

    if (n % 2 == 0) {
        puts("NO");
        return 0;
    }

    add(1, 1);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (sz[cur] % 2 == 0 && !vis[cur]) {
            dfs(cur);
        }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
