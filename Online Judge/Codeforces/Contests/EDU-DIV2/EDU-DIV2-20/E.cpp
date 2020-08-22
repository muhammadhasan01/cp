#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const char CC[2] = {'W', 'L'};

int n, k;
char a[N];
bool dp[N][N][2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= (i == n ? k : k - 1); j++) {
            for (int x = 0; x < 2; x++) {
                if (a[i] == '?' || a[i] == 'D') {
                    if (dp[i - 1][j][x]) {
                        dp[i][j][x] = 1;
                    }
                }
                if (j > 0 && dp[i - 1][j - 1][x]) {
                    if (a[i] == '?' || a[i] == CC[x]) {
                        dp[i][j][x] = 1;
                    }
                }
                int y = 1 - x;
                if (dp[i - 1][j + 1][y]) {
                    if (a[i] == '?' || a[i] == CC[x]) {
                        dp[i][j][y] = 1;
                        if (j == 0)
                            dp[i][j][x] = 1;
                    }
                }
            }
        }
    }
    int x = 0;
    bool ok = false;
    if (dp[n][k][x]) {
        ok = true;
    } else if (dp[n][k][1 - x]) {
        ok = true;
        x = 1 - x;
    }
    if (!ok) {
        cout << "NO" << '\n';
        return 0;
    }
    int i = n, j = k, it = x;
    while (i >= 1) {
        if (dp[i - 1][j][it]) {
            if (a[i] == '?' || a[i] == 'D') {
                a[i] = 'D'; i--;
                continue;
            }
        }
        if (dp[i - 1][j][1 - it]) {
            if (a[i] == '?' || a[i] == 'D') {
                a[i] = 'D', i--, it ^= 1;
                continue;
            }
        }
        if (j > 0 && dp[i - 1][j - 1][it]) {
            if (a[i] == '?' || a[i] == CC[it]) {
                a[i] = CC[it];
                i--, j--;
                continue;
         
            }
        }
        if (dp[i - 1][j + 1][1 - it]) {
            if (a[i] == '?' || a[i] == CC[it]) {
                a[i] = CC[it];
                if (j == 0) it ^= 1;
                i--, j++;
                continue;
            }
        }
        if (dp[i - 1][j + 1][it]) {
            if (a[i] == '?' || a[i] == CC[1 - it]) {
                a[i] = CC[1 - it];
                i--, j++;
                continue;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << '\n';

    return 0;
}