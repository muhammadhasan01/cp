#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int K = 2505;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> str;
    int n = str.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            ++cnt;
        }
    }
    if (cnt == 0 || cnt == n) {
        cout << 0 << '\n';
        return 0;
    }
    if (cnt > n / 2) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                str[i] = '0';
            } else {
                str[i] = '1';
                ++cnt;
            }
        }
    }
    vector<vector<int>> dp(cnt + 1, vector<int>(2 * K + 5, INF));
    dp[0][K] = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> ndp(cnt + 1, vector<int>(2 * K + 5, INF));
        int cc = min(i + 1, cnt);
        for (int c = 0; c <= cc; c++) {
            for (int sum = -K; sum <= K; sum++) {
                int s = sum + K;
                if (dp[c][s] == INF) {
                    continue;
                }
                int c1 = c;
                int c2 = i - c;
                // put 0
                int sum0 = sum - c1;
                if (sum0 >= -K) {
                    sum0 += K;
                    ndp[c1][sum0] = min(ndp[c1][sum0], dp[c][s] + (str[i] != '0'));
                }
                // put 1
                int sum1 = sum + c2;
                if (c1 + 1 <= cc && sum1 <= K) {
                    sum1 += K;
                    ndp[c1 + 1][sum1] = min(ndp[c1 + 1][sum1], dp[c][s] + (str[i] != '1'));
                }
            }
        }
        dp.swap(ndp);
    }
    cout << dp[cnt][K] / 2 << '\n';
    
    return 0;
}