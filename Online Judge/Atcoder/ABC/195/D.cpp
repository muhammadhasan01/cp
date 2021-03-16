#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 55;

int n, m, q;
pair<int, int> p[N];
int x[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        vector<int> v = {-1};
        for (int i = 1; i <= m; i++) {
            if (l <= i && i <= r) continue;
            v.emplace_back(x[i]);
        }
        sort(v.begin(), v.end());
        int len = v.size() - 1;
        vector<vector<int>> dp(n + 1, vector<int>(len + 1));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= len; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (p[i].first <= v[j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + p[i].second);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}