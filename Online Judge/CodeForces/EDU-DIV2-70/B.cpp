#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
string s;
long long ans[15][15];
int dp[105][15][15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            for (int h = 0; h <= 100; h++) {
                dp[h][i][j] = inf;
                if (h == 0) {
                    dp[h][i][j] = 0;
                } else {
                    if (h >= i) {
                        dp[h][i][j] = min(dp[h][i][j], dp[h - i][i][j] + 1);
                    }
                    if (h >= j) {
                        dp[h][i][j] = min(dp[h][i][j], dp[h - j][i][j] + 1);
                    }
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            int res = 0;
            for (int k = 1; k < s.size(); k++) {
                int cur = s[k] - s[k - 1];
                int minn = inf;
                if (cur < 0) cur += 10;
                if (cur == 0) {
                    if (i == 0 || j == 0) {
                        minn = 1;
                    } else {
                        cur += 10;
                    }
                }
                while (cur <= 100) {
                    minn = min(minn, dp[cur][i][j]);
                    cur += 10;
                }
                if (minn == inf) {
                    res = -1;
                    break;
                } else {
                    res += max(0, minn - 1);
                }
            }
            ans[i][j] = res;
            ans[j][i] = res;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << ans[i][j] << (j == 9 ? '\n' : ' ');
        }
    }

    return 0;
}
