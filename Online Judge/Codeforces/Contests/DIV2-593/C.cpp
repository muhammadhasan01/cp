#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;
int n;
int ans[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int k = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (i & 1) {
            for (int j = 1; j <= n; j++) {
                ans[j][i] = ++k;
            }
        } else {
            for (int j = n; j >= 1; j--) {
                ans[j][i] = ++k;
            }
        }
    }
    k = n * n;
    for (int i = n; i >= n / 2 + 1; i--) {
        if ((n - i + 1) & 1) {
            for (int j = 1; j <= n; j++) {
                ans[j][i] = k--;
            }
        } else {
            for (int j = n; j >= 1; j--) {
                ans[j][i] = k--;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << (j == n ? '\n' : ' ');
        }
    }

    return 0;
}
