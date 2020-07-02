#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n, m;
char a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = ((i + j) % 2 == 0 ? 'B' : 'W');
            }
        }
        if ((n * m) % 2 == 0) {
            bool flag = false;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == 'W') {
                        a[i][j] = 'B';
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}