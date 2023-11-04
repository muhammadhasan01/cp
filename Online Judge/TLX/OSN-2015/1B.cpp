#include <bits/stdc++.h>

using namespace std;

const int K = 6;
const string KIRI_ATAS = "Kiri Atas";
const string KANAN_BAWAH = "Kanan Bawah";
const string TIDAK_MUNGKIN = "Tidak Mungkin";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string useless;
    cin >> useless;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 2, vector<int>(K)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            double L = g[i][j] >= g[i][j - 1];
            double R = g[i][j] >= g[i][j + 1];
            double U = g[i][j] >= g[i - 1][j];
            double D = g[i][j] >= g[i + 1][j];
            dp[i][j][0] = (L && R && U && D);
            dp[i][j][1] = (L && R);
            dp[i][j][2] = (U && D && R);
            dp[i][j][3] = (U && D && L);
            dp[i][j][4] = (L && R && D);
            dp[i][j][5] = (L && R && U);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < K; k++) {
                dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k]; 
            }
        }
    }

    auto getSum = [&](int x1, int y1, int x2, int y2, int t) -> int {
        return dp[x2][y2][t] - dp[x2][y1 - 1][t] - dp[x1 - 1][y2][t] + dp[x1 - 1][y1 - 1][t];
    };

    auto solveQuery = [&](int a, int b, int c, int d) -> string {
        bool isSwapped = false;
        if (a > c) {
            swap(a, c);
            isSwapped = true;
        }
        if (a == c) {
            if (getSum(a, b + 1, c, d - 1, 1) > 0) {
                return TIDAK_MUNGKIN;
            }
            if (g[a][b] > g[a][b + 1] && g[c][d] < g[c][d - 1]) {
                return KIRI_ATAS;
            }
            if (g[a][b] < g[a][b + 1] && g[c][d] > g[c][d - 1]) {
                return KANAN_BAWAH;
            }
            return TIDAK_MUNGKIN;
        }
        int sum = 0;
        sum += getSum(a + 1, b + 1, c - 1, d - 1, 0);
        sum += getSum(a + 1, b, c - 1, b, 2) + getSum(a + 1, d, c - 1, d, 3);
        sum += getSum(a, b + 1, a, d - 1, 4) + getSum(c, b + 1, c, d - 1, 5);
        if (sum > 0) {
            return TIDAK_MUNGKIN;
        }
        int LU = g[a][b] > g[a + 1][b] && g[a][b] > g[a][b + 1];
        int RU = g[a][d] > g[a + 1][d] && g[a][d] > g[a][d - 1];
        int LD = g[c][b] > g[c - 1][b] && g[c][b] > g[c][b + 1];
        int RD = g[c][d] > g[c - 1][d] && g[c][d] > g[c][d - 1];
        int superior = LU + LD + RU + RD;
        if (superior != 1) {
            return TIDAK_MUNGKIN;
        }
        if (isSwapped) {
            if (LD) {
                return KIRI_ATAS;
            }
            if (RU) {
                return KANAN_BAWAH;
            }
            return TIDAK_MUNGKIN;
        }
        if (LU) {
            return KIRI_ATAS;
        }
        if (RD) {
            return KANAN_BAWAH;
        }
        return TIDAK_MUNGKIN;
    };

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solveQuery(a, b, c, d) << '\n';
    }

    return 0;
}