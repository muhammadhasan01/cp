#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 1e9 + 7;
int h, w;
short int a[N][N];
int r[N], c[N];

long long fast(long long x, int y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % M;
        }
        y >>= 1;
        x = (x * x) % M;
    }
    return (res % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            a[i][j] = -1;
        }
    }
    for (int i = 1; i <= h; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= w; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= r[i]; j++) {
            a[i][j] = 1;
        }
        a[i][r[i] + 1] = 0;
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= c[i]; j++) {
            if (a[j][i] == 0) {
                puts("0");
                return 0;
            }
            a[j][i] = 1;
        }
        if (a[c[i] + 1][i] == 1) {
            puts("0");
            return 0;
        } else {
            a[c[i] + 1][i] = 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == -1) cnt++;
        }
    }
    cout << fast(2, cnt) << '\n';

    return 0;
}
