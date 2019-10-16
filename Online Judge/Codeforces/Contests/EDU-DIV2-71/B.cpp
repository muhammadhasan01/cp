#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, m;
bool a[N][N], vis[N][N], b[N][N];

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
    vector<pair<int,int>> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                if (i + 1 > n || j + 1 > m) continue;
                if (a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
                    ans.push_back({i, j});
                }
            }
        }
    }
    for (auto e : ans) {
        int k1 = e.first, k2 = e.second;
        b[k1][k2] = b[k1 + 1][k2] = b[k1][k2 + 1] = b[k1 + 1][k2 + 1] = 1;
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ok &= (a[i][j] == b[i][j]);
        }
    }
    if (ok) {
        cout << ans.size() << '\n';
        for (auto e : ans) {
            cout << e.first << " " << e.second << '\n';
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
