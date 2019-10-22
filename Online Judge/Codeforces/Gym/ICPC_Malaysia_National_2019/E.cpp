// author : m.hasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int tc;
int n;
bool dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> tc;
        if (tc == 0) break;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) cin >> v[n - i + 1];
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int i = 1; i <= tc; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= v[j]) {
                    dp[i][j] |= dp[i - v[j]][j - 1];
                }
            }
        }
        for (int i = tc; i >= 1; i--) {
            if (dp[i][n]) {
                vector<int> ans;
                int pos = i, k = n;
                while (k >= 1) {
                    if (v[k] <= pos && dp[pos - v[k]][k - 1]) {
                        ans.push_back(v[k]);
                        pos -= v[k];
                        k--;
                    } else {
                        k--;
                    }
                }
                for (auto e : ans) cout << e << " ";
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
