#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 1005;

int tc;
int n, m, x, y;
char a[N][M];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        long long ans = 0;
        if (2 * x <= y) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == '.') ans += (1LL) * x;
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                int len = 0;
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == '.') {
                        ++len;
                    } else {
                        if (len % 2 == 0) {
                            ans += (1LL) * y * (len / 2);
                        } else {
                            ans += (1LL) * x + (1LL) * y * ((len - 1) / 2);
                        }
                        len = 0;
                    }
                }
                if (len % 2 == 0) {
                    ans += (1LL) * y * (len / 2);
                } else {
                    ans += (1LL) * x + (1LL) * y * ((len - 1) / 2);
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}