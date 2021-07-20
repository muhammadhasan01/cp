#include <bits/stdc++.h>

using namespace std;

const int N = 23;
const int M = (1 << N) + 5;

int n, m;
int nodes;
bitset<M> vis, have;

void dfs(int u) {
    vis[u] = 1;
    if (u <= nodes) {
        for (int i = 0; i < n; i++) {
            bool b = (u & (1 << i));
            if (b) {
                continue;
            }
            int v = (u | (1 << i));
            if (vis[v] == 0) {
                dfs(v);
            }
        }
        int complement = nodes - u + (1 << n);
        if (have[complement - (1 << n)] == 1 && vis[complement] == 0) {
            dfs(complement);
        }
    } else {
        int v = u - (1 << n);
        if (vis[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        have[a[i]] = 1;
    }
    nodes = (1 << n) - 1;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int cur = a[i] + (1 << n);
        if (vis[cur] == 1) {
            continue;
        }
        dfs(cur);
        ans = ans + 1;
    }
    cout << ans << '\n';

    return 0;
}