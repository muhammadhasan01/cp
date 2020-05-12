#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int root;
bool c[N];
vector<int> g[N];
vector<int> leaves;

void dfs(int u, int p) {
    for (auto v : g[u]) {
        if (v == p) continue;
        c[v] = !(c[u]);
        dfs(v, u);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() == 1) {
            leaves.push_back(i);
        }
    }
    root = leaves[0];
    dfs(root, root);
    int minimumF = 1;
    for (auto& e : leaves) {
        if (c[e]) {
            minimumF = 3;
            break;
        }
    }
    int maksimumF = n - 1 - (int) leaves.size();
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (auto& j : g[i]) {
            if ((int) g[j].size() == 1) {
                flag = true;
                break;
            }
        }
        if (flag) maksimumF++;
    }
    cout << minimumF << " " << maksimumF << '\n';

    return 0;
}