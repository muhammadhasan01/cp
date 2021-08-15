#include <bits/stdc++.h>

using namespace std;
using ld = long double;

const int K = 6;
const int N = (1 << K) + 5;

ld a[N][N];
ld p[K + 5][N], dp[K + 5][N];

void gen(int h, int s, int e) {
    if (s == e) {
        p[h][s] = 1.0;
        return;
    }
    int mid = (s + e) >> 1;
    gen(h - 1, s, mid);
    gen(h - 1, mid + 1, e);
    for (int u = s; u <= e; u++) {
        int l = mid + 1, r = e;
        if (u > mid) {
            l = s, r = mid;
        }
        for (int v = l; v <= r; v++) {
            p[h][u] += p[h - 1][v] * a[u][v];
        }
        p[h][u] *= p[h - 1][u];
        for (int v = l; v <= r; v++) {
            dp[h][u] = max(dp[h][u], dp[h - 1][u] + dp[h - 1][v] + p[h][u] * (1 << (h - 1)));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m = (1 << n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] /= 100.0;
        }
    }
    gen(n, 1, m);
    ld ans = 0.0;
    for (int u = 1; u <= m; u++) {
        ans = max(ans, dp[n][u]);
    }
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}