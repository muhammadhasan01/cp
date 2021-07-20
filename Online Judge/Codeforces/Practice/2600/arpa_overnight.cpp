#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int boy[N], girl[N];
int ans[N];
vector<int> adj[N];

void dfs(int u, int col) {
    ans[u] = col;
    for (int v : adj[u]) {
        if (ans[v] > 0) {
            continue;
        }
        dfs(v, 3 - col);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> boy[i] >> girl[i];
        adj[boy[i]].emplace_back(girl[i]);
        adj[girl[i]].emplace_back(boy[i]);
        adj[2 * i].emplace_back(2 * i + 1);
        adj[2 * i + 1].emplace_back(2 * i);
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (ans[i] > 0) {
            continue;
        }
        dfs(i, 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[boy[i]] << ' ' << ans[girl[i]] << '\n';
    }

    return 0;
}