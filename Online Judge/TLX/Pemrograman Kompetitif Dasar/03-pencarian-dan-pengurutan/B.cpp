#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int res = 1;
            for (int it = 0; it < K; it++) {
                int ci = i + dx[it];
                int cj = j + dy[it];
                if (ci < 1 || cj < 1 || ci > n || cj > m) {
                    continue;
                }
                res = res * a[ci][cj];
            }
            if (res == k) {
                cout << i << " " << j << '\n';
                return 0;
            }
        }
    }
    cout << 0 << " " << 0 << '\n';
    
    return 0;
}