#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;
int n, m;
int par[N], dp[N];
int ans = 0;

int fpar(int x) {
    return (x == par[x] ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (pu > pv) swap(pu, pv);
    par[pv] = pu;
    dp[pu] = max(dp[pu], dp[pv]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = dp[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int l = 1;
    int r = dp[l];
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int k = fpar(i);
        if (i == k && r > i) {
            merge(l, i);
            r = dp[l];
            ans++;
        } else if (i == k && i > r) {
            l = i, r = dp[i];
        }
    }
    cout << ans << '\n';

    return 0;
}
