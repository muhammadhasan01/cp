#include <bits/stdc++.h>

using namespace std;

const int INF = 1e3;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int maxi = (n + m - 1) * INF;
    int mini = (n + m - 1);
    if (max(a, b) > maxi || min(a, b) < mini) {
        cout << "Impossible\n";
        return;
    }
    vector<vector<int>> mat(n + 1, vector<int>(m + 1, INF));
    int res_a = maxi, res_b = maxi;
    if (m >= n) {
        for (int i = 1; i <= m; i++) {
            int cur = min({INF - 1, res_a - a, res_b - b});
            if (cur == 0) {
                break;
            }
            mat[1][i] -= cur;
            res_a -= cur;
            res_b -= cur;
        }
        for (int j = 2; j <= n; j++) {
            if (res_a > a) {
                int cur = min({INF - 1, res_a - a});
                mat[j][m] -= cur;
                res_a -= cur;
            }
            if (res_b > b) {
                int cur = min({INF - 1, res_b - b});
                mat[j][1] -= cur;
                res_b -= cur;
            }
        }
        if (res_a != a || res_b != b) {
            cout << "Impossible\n";
            return;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            int cur = min({INF - 1, res_a - a, res_b - b});
            if (cur == 0) {
                break;
            }
            mat[i][1] -= cur;
            res_a -= cur;
            res_b -= cur;
        }
        for (int j = 2; j <= m; j++) {
            if (res_a > a) {
                int cur = min({INF - 1, res_a - a});
                mat[n][j] -= cur;
                res_a -= cur;
            }
            if (res_b > b) {
                int cur = min({INF - 1, res_b - b});
                mat[1][j] -= cur;
                res_b -= cur;
            }
        }
        if (res_a != a || res_b != b) {
            cout << "Impossible\n";
            return;
        }
    }
    cout << "Possible\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mat[i][j] << " \n"[j == m];
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}