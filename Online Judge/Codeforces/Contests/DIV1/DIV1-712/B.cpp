#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int g[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int rep = 1; rep <= n * n; rep++) {
        int a;
        cin >> a;
        int b = -1, x = -1, y = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][j] == 0 && (i + j) % 2 == 0 && a != 1) {
                    b = 1, x = i, y = j;
                    break;
                }
            }
            if (b != -1) break;
        }
        if (b == -1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (g[i][j] == 0 && (i + j) % 2 == 1 && a != 2) {
                        b = 2, x = i, y = j;
                        break;
                    }
                }
                if (b != -1) break;
            }
            if (b == -1) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (g[i][j] == 0) {
                            b = 3, x = i, y = j;
                            break;
                        }
                    }
                    if (b != -1) break;
                }
            }
        }
        cout << b << ' ' << x << ' ' << y << endl;
        g[x][y] = b;
    }

    return 0;
}