#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
char a[N];
int par[N], sz[N];

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        par[i] = i, sz[i] = 1;
    }
    vector<bool> good(n + 1);
    for (int i = 1; i < n; i++) {
        if (a[i] == 'R' && a[i + 1] == 'L')
            good[i] = good[i + 1] = 1;
    }
    if (a[n] == 'R' && a[1] == 'L')
        good[n] = good[1] = 1;
    for (int i = 1; i < n; i++) {
        if (good[i] || good[i + 1]) continue;
        if (a[i] != a[i + 1]) continue;
        merge(i, i + 1);
    }
    if (good[n] == 0 && good[1] == 0 && a[n] == a[1]) {
        merge(1, n);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (good[i]) continue;
        if (i != fpar(i)) continue;
        if (sz[i] == n) {
            cout << (n + 2) / 3 << '\n';
            return;
        } else {
            ans += (sz[i] + 1) / 3;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}