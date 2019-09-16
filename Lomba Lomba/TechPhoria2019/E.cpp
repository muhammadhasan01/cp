#include <bits/stdc++.h>
using namespace std;

int g;
int b, k;
char a[55][55];
int x[55][55][55][5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> g;
    while (g--) {
        cin >> b >> k;

        memset(x, 0, sizeof(x));

        vector<pair<int,int>> le, ri, up, dn;
        vector<vector<bool>> vis(b + 3, vector<bool>(k + 3, 0));

        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= k; j++) {
                cin >> a[i][j];
                if (a[i][j] == '>') {
                    ri.push_back({i, j});
                } else if (a[i][j] == '<') {
                    le.push_back({i, j});
                } else if (a[i][j] == '^') {
                    up.push_back({i, j});
                } else if (a[i][j] == 'O') {
                    vis[i][j] = 1;
                } else if (a[i][j] == 'v') {
                    dn.push_back({i, j});
                }
            }
        }


        int maks = max(b, k);
        for (auto e : le) {
            int p = 1;
            int k1 = e.first, k2 = e.second;
            while (1 <= k1 && k1 <= b && 1 <= k2 && k2 <= k && vis[k1][k2] == 0) {
                x[k1][k2][p++][1]++;
                k2--;
            }
        }
        for (auto e : ri) {
            int p = 1;
            int k1 = e.first, k2 = e.second;
            while (1 <= k1 && k1 <= b && 1 <= k2 && k2 <= k && vis[k1][k2] == 0) {
                x[k1][k2][p++][2]++;
                k2++;
            }
        }
        for (auto e : up) {
            int p = 1;
            int k1 = e.first, k2 = e.second;
            while (1 <= k1 && k1 <= b && 1 <= k2 && k2 <= k && vis[k1][k2] == 0) {
                x[k1][k2][p++][3]++;
                k1--;
            }
        }
        for (auto e : dn) {
            int p = 1;
            int k1 = e.first, k2 = e.second;
            while (1 <= k1 && k1 <= b && 1 <= k2 && k2 <= k && vis[k1][k2] == 0) {
                x[k1][k2][p++][4]++;
                k1++;
            }
        }
        long long ans = 0;
        for (int t = 1; t <= maks; t++) {
            for (int i = 1; i <= b; i++) {
                for (int j = 1; j <= k; j++) {
                    long long cur = 0;
                    for (int m = 1; m <= 4; m++) {
                        cur += x[i][j][t][m];
                    }
                    ans += cur * (cur - 1) / 2;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
