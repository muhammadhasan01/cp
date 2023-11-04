#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int len = 2; len <= n; len += 2) {
        for (int l = 0; l < n; l++) {
            int r = l + len - 1;
            if (r >= n) {
                break;
            }
            if (len == 2) {
                dp[l][r] = (s[l] == s[r] ? 0 : 1);
                continue;
            }
            vector<tuple<int, int, int, int>> rec = {
                make_tuple(l, l + 1, l + 2, r),
                make_tuple(l, r, l + 1, r - 1),
                make_tuple(r, r - 1, l, r - 2),
                make_tuple(r, l, l + 1, r - 1)
            };
            for (int i = 0; i < 4; i += 2) {
                auto [pos, x, xl, xr] = rec[i];
                auto [_, y, yl, yr] = rec[i + 1];
                if (dp[xl][xr] == -1 || dp[yl][yr] == -1) {
                    continue;
                } else if (dp[xl][xr] == 1 && dp[yl][yr] == 1) {
                    dp[l][r] = 1;
                    break;
                } else if (dp[xl][xr] == 0 && dp[yl][yr] == 0) {
                    char cc = min(s[x], s[y]);
                    if (cc > s[pos]) {
                        dp[l][r] = 1;
                        break;
                    } else if (cc == s[pos]) {
                        dp[l][r] = 0;
                    }
                    continue;
                } else if (dp[xl][xr] == 1 && dp[yl][yr] == 0) {
                    if (s[y] > s[pos]) {
                        dp[l][r] = 1;
                        break;
                    } else if (s[y] == s[pos]) {
                        dp[l][r] = 0;
                    }
                } else if (dp[xl][xr] == 0 && dp[yl][yr] == 1) {
                    if (s[x] > s[pos]) {
                        dp[l][r] = 1;
                        break;
                    } else if (s[x] == s[pos]) {
                        dp[l][r] = 0;
                    }
                }
            }
        }
    }
    int res = dp[0][n - 1];
    if (res == 1) {
        cout << "Alice" << '\n';
    } else if (res == 0) {
        cout << "Draw" << '\n';
    } else if (res == -1) {
        cout << "Bob" << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}