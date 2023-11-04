#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    int len = INT_MAX;
    int x = -1, y = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'R') {
                int cur = (i - 1) + (j - 1);
                if (cur < len) {
                    len = cur;
                    x = i - 1;
                    y = j - 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'R') {
                int ci = i - x;
                int cj = j - y;
                if (ci <= 0 || cj <= 0) {
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}