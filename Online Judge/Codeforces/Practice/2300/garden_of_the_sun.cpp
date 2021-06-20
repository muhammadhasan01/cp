#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int K = 3;

int n, m;
char a[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int start = (n % K == 1 ? 1 : 2);
    for (int i = start; i <= n; i += K) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = 'X';
        }
        if (i + K > n) break;
        bool flag = false;
        for (int j = 1; j <= m; j++) {
            if (a[i + 1][j] == 'X' || a[i + 2][j] == 'X') {
                a[i + 1][j] = a[i + 2][j] = 'X';
                flag = true;
                break;
            }
        }
        if (!flag) {
            a[i + 1][1] = a[i + 2][1] = 'X';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}