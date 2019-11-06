#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
int a[N], par[N], sz[N], dp[N];
long long ans = 0;
bool vis[N];

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

long long f(long long x) {
    return x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i - 1] > a[i]) merge(i, i - 1);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = fpar(i);
        if (vis[k]) {
            dp[i] = dp[i - 1];
            continue;
        }
        vis[k] = 1;
        int siz = sz[k];
        if (i == 1) {
            ans += f(siz);
            dp[i] = 1;
        } else if (a[i - 1] < a[i]) {
            if (siz > 1) {
                ans += f(siz) + (1LL) * max(0, dp[i - 1] + 1 - siz);
                dp[i] = 1;
            } else {
                dp[i] = dp[i - 1] + 1;
                ans += (1LL) * dp[i];
            }
        } else if (a[i - 1] == a[i]) {
            ans += f(siz);
            dp[i] = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
