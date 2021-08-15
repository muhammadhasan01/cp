#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e9 + 7;

int n;
int par[N];
bool is_self[N];
int comp[N];
int to[N];

int fpar(int u) {
    return (par[u] == u ? u : par[u] = fpar(par[u]));
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    par[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        par[i] = i;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        to[u] = v;
        if (u == v) {
            is_self[u] = 1;
        }
        merge(u, v);
    }
    for (int i = 1; i < N; i++) {
        int pp = fpar(i);
        comp[pp]++;
        if (is_self[i]) {
            is_self[pp] = true;
        }
    }
    long long ans = 1;
    for (int c = 1; c < N; c++) {
        if (is_self[c] || comp[c] <= 1) {
            continue;
        }
        set<int> vis;
        int u = c;
        bool cycle = false;
        while (true) {
            if (vis.find(u) != vis.end()) {
                cycle = true;
                break;
            }
            vis.emplace(u);
            if (to[u] == 0) {
                break;
            }
            u = to[u];
        }
        long long cur = comp[c];
        if (cycle) {
            cur = 2;
        }
        ans = (ans * cur) % M;
    }
    cout << ans << '\n';

    return 0;
}