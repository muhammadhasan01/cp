#include <bits/stdc++.h>

using namespace std;

const int A = 10005;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp(A, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> ndp = dp;
        for (int x = 0; x + a[i] < A; x++) {
            int nx = x + a[i];
            for (int k = 0; k + 1 <= n; k++) {
                if (dp[x][k] == -1) {
                    continue;
                }
                ndp[nx][k + 1] = max(ndp[nx][k + 1], dp[x][k] + b[i]);
            }
        }
        dp.swap(ndp);
    }
    vector<int> ans(n + 1);
    int B = accumulate(b.begin(), b.end(), 0);
    for (int x = 0; x < A; x++) {
        for (int k = 0; k <= n; k++) {
            if (dp[x][k] == -1) {
                continue;
            }
            ans[k] = max(ans[k], min(2 * x, B + dp[x][k]));
        }
    }
    cout << fixed << setprecision(9);
    for (int i = 1; i <= n; i++) {
        double res = ans[i];
        cout << res / 2.0 << " \n"[i == n];
    }
    
    return 0;
}