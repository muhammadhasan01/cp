#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, k;
int a[10][N], pos[10][N], dp[N], ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int t = 1; t <= k; t++) {
        for (int i = 1; i <= n; i++) {
            cin >> a[t][i];
            pos[t][a[t][i]] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j < i; j++) {
            int idx = 2;
            while (idx <= k && pos[idx][a[1][j]] < pos[idx][a[1][i]]) idx++;
            if (idx == k + 1 && dp[j] > cur) {
                cur = dp[j];
            }
        }
        dp[i] = cur + 1;
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}
