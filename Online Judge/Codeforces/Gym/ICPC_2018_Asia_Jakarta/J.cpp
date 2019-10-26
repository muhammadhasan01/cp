#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v[16];
int dp[16][(1 << 16)], pd[16][(1 << 16)];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int it = 1; it <= n; it++) {
        string s;
        cin >> s;
        int len = s.size();
        for (int i = 1; i < (1 << len); i++) {
            string cur = "";
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) cur += s[j];
            }
            v[it].push_back(cur);
        }
        sort(v[it].begin(), v[it].end());
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) v[i].size(); j++) {
            if (i == 1) {
                dp[i][j] = (int) v[i][j].size();
                if (j == 0) {
                    pd[i][j] = dp[i][j];
                } else {
                    pd[i][j] = max(pd[i][j - 1], dp[i][j]);
                }
            } else {
                int k = (int) v[i][j].size();
                int kk = (int) v[i - 1].size();
                int l = 0, r = kk - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (v[i - 1][mid] < v[i][j]) {
                        l = mid + 1;
                        pos = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (pos >= 0 && pd[i - 1][pos] > 0) {
                    dp[i][j] = k + pd[i - 1][pos];
                } else {
                    dp[i][j] = 0;
                }
                if (j == 0) {
                    pd[i][j] = dp[i][j];
                } else {
                    pd[i][j] = max(pd[i][j - 1], dp[i][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < (int) v[n].size(); j++) {
        ans = max(ans, dp[n][j]);
    }
    cout << (ans == 0 ? -1 : ans) << '\n';

    return 0;
}
