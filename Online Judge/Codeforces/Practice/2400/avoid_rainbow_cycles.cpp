#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = N + N;

int m, n;
int a[N], b[N];
int par[M];

int fpar(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = fpar(par[x]);
}

bool merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) {
        return false;
    }
    par[pv] = pu;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < M; i++) {
        par[i] = i;
    }
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<tuple<int, int, int>> edges;
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        int len;
        cin >> len;
        while (len--) {
            int j;
            cin >> j;
            int w = a[i] + b[j];
            edges.emplace_back(i, j + m, w);
            ans += w;
        }
    }
    sort(edges.begin(), edges.end(), [&](auto& x, auto& y) {
        return get<2>(x) > get<2>(y);
    });
    for (auto& [u, v, w] : edges) {
        if (merge(u, v)) {
            ans -= w;
        }
    }
    cout << ans << '\n';

    return 0;
}