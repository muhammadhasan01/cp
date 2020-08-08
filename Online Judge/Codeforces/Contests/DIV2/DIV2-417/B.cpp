#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int M = 105;
const int INF = 1e7;

int n, m;
char a[N][M];
int dp[N][2];
int part[N][2];

void init() {
    for (int i = 1; i <= n; i++) {
        part[i][0] = m + 1;
        part[i][1] = 0;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    int cnt = 0;
    int last = n + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m + 1; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') {
                part[i][0] = min(part[i][0], j);
                part[i][1] = max(part[i][1], j);
            }
        }
        if (part[i][0] == m + 1) {
            swap(part[i][0], part[i][1]);
        } else {
            last = min(last, i);
        }
    }
    dp[n][0] = (part[n][1] == m + 1 ? 0 : 2 * part[n][1] - part[n][0]);
    dp[n][1] = (part[n][1] == m + 1 ? m + 1 : part[n][1]);
    for (int i = n - 1; i >= last; i--) {
        if (part[i][0] == 0) {
            dp[i][0] = min(dp[i + 1][0] + part[i + 1][0], dp[i + 1][1] + part[i + 1][1]) + 1;
            dp[i][1] = min(dp[i + 1][0] + (m + 1 - part[i + 1][0]), dp[i + 1][1] + (m + 1 - part[i + 1][1])) + 1;
        } else {
            dp[i][0] = INF;
            for (int it = 0; it < 2; it++) {
                dp[i][0] = min(dp[i][0], (m + 1 - part[i][0]) + dp[i + 1][it] + (m + 1 - part[i + 1][it]) + 1);
            }
            dp[i][1] = INF;
            for (int it = 0; it < 2; it++) {
                dp[i][1] = min(dp[i][1], part[i][1] + dp[i + 1][it] + part[i + 1][it] + 1);
            }
        }
    }
    cout << min(dp[last][0], dp[last][1]) << '\n';

    return 0;
}