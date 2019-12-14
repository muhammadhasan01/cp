#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9;
int n, m;
char a[N][N];
int suf[N][N];
int t[4 * N][N];

void build(int v, int s, int e, int k) {
    if (s == e) {
        t[v][k] = suf[s][k];
    } else {
        int mid = (s + e) >> 1;
        build(2 * v, s, mid, k);
        build(2 * v + 1, mid + 1, e, k);
        t[v][k] = min(t[2 * v][k], t[2 * v + 1][k]);
    }
}

int get(int v, int s, int e, int l, int r, int k) {
    if (s > r || e < l) {
        return INF;
    }
    if (l <= s && e <= r) {
        return t[v][k];
    }
    int mid = (s + e) >> 1;
    int p1 = get(2 * v, s, mid, l, r, k);
    int p2 = get(2 * v + 1, mid + 1, e, l, r, k);
    return min(p1, p2);
}

bool can(int x) {
    for (int i = 1; i <= n - x + 1; i++) {
        for (int j = 1; j <= m - x + 1; j++) {
            int g = get(1, 1, n, i, i + x - 1, j);
            if (g >= x) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (a[i][j] == a[i][j + 1]) {
                suf[i][j] = suf[i][j + 1] + 1;
            } else {
                suf[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        build(1, 1, n, i);
    }
    int l = 1, r = min(n, m), ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans * ans << '\n';

    return 0;
}
