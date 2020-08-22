#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n, k;
char a[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = '0';
        }
    }
    if (k > n * n) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (k < 2) break;
        for (int j = i; j <= n; j++) {
            if (k < 2) break;
            a[i][j] = a[j][i] = '1';
            k -= (i == j ? 1 : 2);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i][i] == '1') continue;
        if (k > 0) {
            a[i][i] = '1';
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << (j == n ? '\n' : ' ');
        }
    }

    return 0;
}