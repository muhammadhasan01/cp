#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
vector<int> a[N];
map<pair<int, int>, int> m;
vector<int> g[N];
int f[N];
bool vis[N];

void dfs(int u, int p) {
    for (auto v : g[u]) {
        if (v == p) continue;
        for (auto e : a[v]) {
            if (vis[e]) continue;
            cout << e << " ";
            vis[e] = 1;
        }
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n -= 2;
    for (int i = 1; i <= n; i++) {
        a[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            f[a[i][j]]++;
        }
        sort(a[i].begin(), a[i].end());
        pair<int,int> x[3];
        x[0] = {a[i][0], a[i][1]};
        x[1] = {a[i][0], a[i][2]};
        x[2] = {a[i][1], a[i][2]};
        for (int j = 0; j < 3; j++) {
            if (m[x[j]] == 0) {
                m[x[j]] = i;
            } else {
                int k = m[x[j]];
                g[i].push_back(k);
                g[k].push_back(i);
            }
        }
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() == 1) {
            root = i;
            break;
        }
    }
    for (int j = 0; j < 3; j++) {
        int cur = a[root][j];
        if (f[cur] == 1) {
            cout << cur << " ";
            vis[cur] = 1;
        }
    }
    for (int j = 0; j < 3; j++) {
        int cur = a[root][j];
        if (f[cur] == 2) {
            cout << cur << " ";
            vis[cur] = 1;
        }
    }
    for (int j = 0; j < 3; j++) {
        int cur = a[root][j];
        if (f[cur] == 3) {
            cout << cur << " ";
            vis[cur] = 1;
        }
    }
    dfs(root, root);

    return 0;
}
