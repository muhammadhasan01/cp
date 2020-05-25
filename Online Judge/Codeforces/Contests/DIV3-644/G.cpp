#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n, m, a, b;
char ans[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> a >> b;
        if (n * a != b * m) {
            cout << "NO" << '\n';
            continue;
        }
        int g = __gcd(n, m);
        int gm = m / g, gn = n / g;
        int k = a / gm;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = i / gn;
                int y = j / gm;
                int bound = x + k - 1;
                if (bound < g) {
                    if (y >= x && y <= bound) {
                        ans[i][j] = '1';
                    } else {
                        ans[i][j] = '0';
                    }
                } else {
                    if (y >= x || y <= (bound % g)) {
                        ans[i][j] = '1';
                    } else {
                        ans[i][j] = '0';
                    }
                }
            }
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}