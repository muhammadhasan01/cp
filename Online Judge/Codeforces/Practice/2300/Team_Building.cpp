#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 7;
const int K = (1 << M);

int n, p, k;
pair<int, int> a[N];
int s[N][M];
long long dp[2][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> s[i][j];
        }
    }
    sort(a + 1, a + 1 + n, greater<pair<int, int>>());
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = (i & 1);
        int y = (x ^ 1);
        for (int mask = 0; mask < (1 << p); mask++) dp[x][mask] = -1;
        for (int mask = 0; mask < (1 << p); mask++) {
            int bit = __builtin_popcount(mask);
            dp[x][mask] = max(dp[x][mask], dp[y][mask]);
            if (i - bit <= k && dp[y][mask] != -1) {
                dp[x][mask] = max(dp[x][mask], dp[y][mask] + a[i].first);
            }
            for (int j = 0; j < p; j++) {
                bool b = (mask & (1 << j));
                if (!b) continue;
                int bmask = (mask ^ (1 << j));
                if (dp[y][bmask] != -1)
                    dp[x][mask] = max(dp[x][mask], dp[y][bmask] + s[a[i].second][j]);
            }
        }
    }
    cout << dp[(n & 1)][(1 << p) - 1] << '\n';

    return 0;
}