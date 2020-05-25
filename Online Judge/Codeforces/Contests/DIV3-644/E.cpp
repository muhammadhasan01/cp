#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n;
char a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            a[n + 1][i] = a[i][n + 1] = '1';
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == '1')  {
                    if (a[i + 1][j] == '1' || a[i][j + 1] == '1') {
                        continue;
                    }
                    flag = false;
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}