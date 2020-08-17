#include <bits/stdc++.h>

using namespace std;

const int N = 30;
const long long M = (1e16);

int n;
long long a[N][N];
long long pre[N][N];

long long getI(int i, int x, int y) {
    long long ret = 0;
    for (int j = x; j <= y; j++)
        ret += a[i][j];
    return ret;
}

long long getJ(int j, int x, int y) {
    long long ret = 0;
    for (int i = x; i <= y; i++)
        ret += a[i][j];
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int j = 2; j <= n; j++) {
        a[n - 1][j] = 1;
    }
    long long maks = n - 1;
    for (int i = n - 2; i >= 1; i--) {
        for (int j = 2; j <= n; j++) {
            long long cur = maks - (getI(i, 2, j - 1) + getJ(j, i + 1, n)) + 1;
            a[i][j] = cur;
            maks = getI(i, 2, j) + getI(i + 1, j, n) + getJ(n, i + 2, n);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
            if (j == n) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = n; i >= 1; i--) {
            pre[i][j] = a[i][j] + pre[i + 1][j];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        cout << 1 << " " << 1 << endl;
        int x = 1, y = 1;
        while (1) {
            if (y + 1 <= n && pre[x][y + 1] <= k) {
                y++;
            } else if (x + 1 <= n && pre[x + 1][y] <= k) {
                x++;
            } else {
                assert(false);
            }
            k -= a[x][y];
            cout << x << " " << y << endl;
            if (x == n && y == n) break;
        }
    }

    return 0;
}