#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int K = 1e3 + 2;

int n, k;
char a[N];
int dp[K][N];
int par[K][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][K] = 1;
    for (int i = 0; i < n; i++) {
        for (int x = -k + 1; x < k; x++) {
            int j = K + x;
            if (!dp[i][j]) continue;
            if (a[i + 1] == '?' || a[i + 1] == 'D') {
                dp[i + 1][j] = 1;
                par[i + 1][j] = 0;
            }
            if (a[i + 1] == '?' || a[i + 1] == 'W') {
                dp[i + 1][j + 1] = 1;
                par[i + 1][j + 1] = -1;
            }
            if (a[i + 1] == '?' || a[i + 1] == 'L') {
                dp[i + 1][j - 1] = 1;
                par[i + 1][j - 1] = 1;
            }
        }
    }
    if (!dp[n][K + k] && !dp[n][K - k]) {
        cout << "NO" << '\n';
        return 0;
    }
    int i = n, j = K + k;
    if (dp[n][K - k]) j = K - k;
    while (i >= 1) {
        int p = par[i][j];
        if (p == 0)
            a[i] = 'D';
        else if (p == -1)
            a[i] = 'W';
        else if (p == 1)
            a[i] = 'L';
        i--, j += p;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << '\n';

    return 0;
}