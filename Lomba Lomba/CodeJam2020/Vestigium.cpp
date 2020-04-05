#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int tc;
int n;
int a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        int sum = 0, row = 0, col = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i][i];
        }
        for (int i = 1; i <= n; i++) {
            vector<bool> vis(n + 1);
            bool flag = false;
            for (int j = 1; j <= n; j++) {
                if (vis[a[i][j]]) {
                    flag = true;
                    break;
                }
                vis[a[i][j]] = 1;
            }
            if (flag) row++;
        }
        for (int j = 1; j <= n; j++) {
            vector<bool> vis(n + 1);
            bool flag = false;
            for (int i = 1; i <= n; i++) {
                if (vis[a[i][j]]) {
                    flag = true;
                    break;
                }
                vis[a[i][j]] = 1;
            }
            if (flag) col++;
        }
        cout << "Case #" << t << ": " << sum << " " << row << " " << col << '\n';
    }

    return 0;
}