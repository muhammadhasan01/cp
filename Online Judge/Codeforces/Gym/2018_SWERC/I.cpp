// author : m.hasan01 & Mastre
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1e3 + 3;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
bitset<1003> a[N];
int dp[N][N];
int par[N * N], sz[N * N];
pair<int, int> upper_left[N * N], lower_right[N * N];
bitset<1003> vis[N];

int ans[3];

int getIdx(int x, int y) {
    return m * (x - 1) + y;
}

int getArea(int lx, int ly, int rx, int ry) {
    return dp[rx][ry] - dp[lx - 1][ry] - dp[rx][ly - 1] + dp[lx - 1][ly - 1];
}

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
    if (upper_left[pv].fi < upper_left[pu].fi) {
        upper_left[pu] = upper_left[pv];
    } else if (upper_left[pv].fi == upper_left[pu].fi) {
        upper_left[pu].se = min(upper_left[pu].se, upper_left[pv].se);
    }
    if (lower_right[pv].fi > lower_right[pu].fi) {
        lower_right[pu] = lower_right[pv];
    } else if (lower_right[pv].fi == lower_right[pu].fi) {
        lower_right[pu].se = max(lower_right[pu].se, lower_right[pv].se);
    }
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cx > n) continue;
        if (cy < 1 || cy > m) continue;
        if (a[cx][cy] == 0) continue;
        if (vis[cx][cy]) continue;
        vis[cx][cy] = 1;
        merge(getIdx(x, y), getIdx(cx, cy));
        dfs(cx, cy);
    }
}

void cekdong(pair<int, int> kiat, pair<int, int> kaba){
    if (kiat.fi == 1 || kiat.se == 1 || kaba.fi == n || kaba.se == m) return;
    bool bisa = 1;
    
    int locn = kaba.fi - kiat.fi + 1;
    int locm = kaba.se - kiat.se + 1;
    if (locn < 5) return;
    if (locm < 3) return;
    if (getArea(kiat.fi - 1, kiat.se - 1, kiat.fi - 1, kaba.se + 1) != 0 || getArea(kaba.fi + 1, kiat.se - 1, kaba.fi + 1, kaba.se + 1) != 0){
        return;
    }
    if (getArea(kiat.fi - 1, kiat.se - 1, kaba.fi + 1, kiat.se - 1) != 0 || getArea(kiat.fi - 1, kaba.se + 1, kaba.fi + 1, kaba.se + 1) != 0){
        return;
    }
    int x, y;
    for (x=0;x<min(locn, locm);x++){
        if (a[kiat.fi + x][kiat.se + x] == 0) break;
    }
    if (x == min(locn, locm)) return;
    y = locm - 2 * x;

    if (x <= 0 || y <= 0 || (2 * x + y) != locm || (3 * x + 2 * y) != locn) return;
    
    int atas;
    int bawah;
    int kiri;
    int kanan;
    int tengah;
    int midatas;
    int midbawah;

    int comph = x * (2 * x + y);
    int compv = x * (3 * x + 2 * y);
    atas = getArea(kiat.fi, kiat.se, kiat.fi + x - 1, kaba.se);
    tengah = getArea(kiat.fi + x + y, kiat.se, kiat.fi + 2 * x + y - 1, kaba.se);
    bawah = getArea(kiat.fi + 2 * x + 2 * y, kiat.se, kiat.fi + 3 * x + 2 * y - 1, kaba.se);
    kiri = getArea(kiat.fi, kiat.se, kaba.fi, kiat.se + x - 1);
    kanan = getArea(kiat.fi, kaba.se - x + 1, kaba.fi, kaba.se);
    midatas = getArea(kiat.fi + x, kiat.se + x, kiat.fi + x + y - 1, kiat.se + x + y - 1);
    midbawah = getArea(kiat.fi + 2 * x + y, kiat.se + x, kiat.fi + 2 * x + 2 * y - 1, kiat.se + x + y - 1);

    if (midatas != 0 || midbawah != 0) return;
    if (atas == comph && tengah == comph && (bawah - 2 * (x * x)) == 0 && kiri == compv && kanan == compv){
        ans[0]++;
    } else if (atas == comph && tengah == comph && bawah == comph && kiri == compv && kanan == compv){
        ans[1]++;
    } else if (atas == comph && (tengah - x * x) == 0 && bawah == comph && kiri == compv && (kanan - 2 * (x * x)) == 0){
        ans[2]++;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char temp;
            cin >> temp;
            a[i][j] = (temp == '#');
            int curIdx = getIdx(i, j);
            par[curIdx] = curIdx;
            sz[curIdx] = 1;
            upper_left[curIdx] = lower_right[curIdx] = make_pair(i, j);
        }
    }
    for (int i=2;i<n;i++){
        for (int j=2;j<m;j++){
            if (a[i][j] && a[i - 1][j - 1] == 0 && a[i - 1][j] == 0 && a[i][j - 1] == 0 && a[i - 1][j + 1] == 0 && a[i + 1][j - 1] == 0 && a[i + 1][j] == 0 && a[i][j + 1] == 0 && a[i + 1][j + 1] == 0){
                a[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int pre = 0;
        for (int j = 1; j <= m; j++) {
            pre += a[i][j];
            dp[i][j] = pre + dp[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) continue;
            if (!vis[i][j]) {
                vis[i][j] = 1;
                dfs(i, j);
            }
        }
    }
    for (int i=1;i<=n * m;i++){
        if (par[i] == i){
            cekdong(upper_left[i], lower_right[i]);
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << '\n';

    return 0;
}