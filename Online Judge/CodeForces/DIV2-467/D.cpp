#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, s;
vector<int> g[N];
bitset<N> onstack;
bool vis[N][3];
int par[N];
vector<int> path;
bool win = false, draw = false;

void dfs(int u, bool h) {
    draw |= onstack[u];
    if (vis[u][h]) return;

    path.push_back(u);
    onstack[u] = true;
    vis[u][h] = true;

    if (g[u].empty() && h) {
        cout << "Win" << '\n';
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? '\n' : ' ');
        }
        exit(0);
    }

    for (auto e : g[u]) {
        dfs(e, h ^ 1);
    }

    onstack[u] = false;
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    cin >> s;
    dfs(s, 0);
    cout << (draw ? "Draw" : "Lose") << '\n';

    return 0;
}
