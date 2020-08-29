#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m;
int a[N];
int par[N];
int ans[N];
vector<int> v[N], w[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        par[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        int parent = fpar(i);
        v[parent].emplace_back(a[i]);
        w[parent].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].empty()) continue;
        sort(v[i].rbegin(), v[i].rend());
        int len = v[i].size();
        for (int j = 0; j < len; j++) {
            ans[w[i][j]] = v[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}