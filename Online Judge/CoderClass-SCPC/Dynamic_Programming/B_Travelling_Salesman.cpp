// WA (???)
#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int INF = 1e7;

int n;
int mat[N][N];
int dp[(1 << N)][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int maks = (1 << (n - 1));
    for (int i = 0; i < maks; i++) {
        for (int j = 0; j < n - 1; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i < maks; i++) {
        for (int j = 0; j < (n - 1); j++) {
            if (!(i & (1 << j))) continue;
            bool single = true;
            int bfr = (i ^ (1 << j));
            for (int k = 0; k < (n - 1); k++) {
                if (!(bfr & (1 << k))) continue;
                single = false;
                dp[i][j] = min(dp[i][j], dp[bfr][k] + mat[k + 1][j + 1]);
            }
            if (single)
                dp[i][j] = mat[0][j + 1];
        }
    }
    int ans = INF;
    for (int j = 0; j < (n - 1); j++) {
        ans = min(ans, dp[maks - 1][j] + mat[j + 1][0]);
    }
    cout << ans << '\n';

    return 0;
}