#include <bits/stdc++.h>

using namespace std;

const int N = 3e2 + 5;

int tc;
int n, m;
int a[N][N];
int b[N][N];

void solve() {
    cin >> n >> m;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                b[i][j] = 2;
            } else if (i == 1 && j == m) {
                b[i][j] = 2;
            } else if (i == n && j == 1) {
                b[i][j] = 2;
            } else if (i == n && j == m) {
                b[i][j] = 2;
            } else if (i == 1 || i == n || j == 1 || j == m) {
                b[i][j] = 3;
            } else {
                b[i][j] = 4;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] > b[i][j]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << (j == m ? '\n' : ' ');
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}