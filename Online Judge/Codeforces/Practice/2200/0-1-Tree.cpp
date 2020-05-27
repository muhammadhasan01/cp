#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
vector<pair<int, int>> g[N];
int col[N];
int par[N], sz[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

long long F(long long x) {
    return x * (x - 1);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
        col[i] = w;
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int zero = -1, one = -1;
        for (auto& e : g[i]) {
            if (col[e.second] == 0) {
                if (zero == -1) {
                    zero = e.second;
                } else {
                    merge(zero, e.second);
                }
            } else {
                if (one == -1) {
                    one = e.second;
                } else {
                    merge(one, e.second);
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (fpar(i) == i) {
            ans += F(sz[i] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        int zero = -1, one = -1;
        for (auto& e : g[i]) {
            if (col[e.second] == 0) {
                zero = e.second;
            } else {
                one = e.second;
            }
            if (zero != -1 && one != -1) break;
        }
        if (zero == -1 || one == -1) continue;
        ans += (1LL) * (sz[fpar(zero)]) * (sz[fpar(one)]);
    }
    cout << ans << '\n';

    return 0;
}