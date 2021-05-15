#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int a[N][N];

void solve() {
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }
    int cur = 0;
    for (int j = 1; j < n; j++) {
        for (int i = 1, k = 0; i <= n - j + 1; i++, k++) {
            a[i][j + k] = ++cur;
        }
    }
    for (int i = 2; i < n; i++) {
        for (int j = 1, k = 0; j <= n - i + 1; j++, k++) {
            a[i + k][j] = ++cur;
        }
    }
    a[1][n] = ++cur;
    a[n][1] = ++cur;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n"[j == n];
        }
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