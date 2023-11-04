#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(3, vector<char>(n + 2));
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> lft(n + 2, 1), rgt(n + 2, 1);
    lft[0] = 0;
    rgt[n + 1] = 0;
    for (int j = 1; j <= n; j++) {
        if (a[1][j] == '.' && a[2][j] == '.') {
            lft[j] = 0;
        } else {
            break;
        }
    }
    for (int j = n; j >= 1; j--) {
        if (a[1][j] == '.' && a[2][j] == '.') {
            rgt[j] = 0;
        } else {
            break;
        }
    }
    vector<vector<int>> pre(3, vector<int>(n + 2));
    {
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= 2; i++) {
                int oi = 3 - i;
                if (a[oi][j] == '*') {
                    pre[i][j] = lft[j - 1] + min(1 + pre[i][j - 1], 1 + pre[oi][j - 1]);
                } else {
                    pre[i][j] = lft[j - 1] + min(pre[i][j - 1], 1 + pre[oi][j - 1]);
                }
            }
        }
    }
    vector<vector<int>> suf(3, vector<int>(n + 2));
    {
        for (int j = n; j >= 1; j--) {
            for (int i = 1; i <= 2; i++) {
                int oi = 3 - i;
                if (a[oi][j] == '*') {
                    suf[i][j] = rgt[j + 1] + min(1 + suf[i][j + 1], 1 + suf[oi][j + 1]);
                } else {
                    suf[i][j] = rgt[j + 1] + min(suf[i][j + 1], 1 + suf[oi][j + 1]);
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= 2; i++) {
            int oi = 3 - i;
            for (int l = 1; l <= 2; l++) {
                for (int r = 1; r <= 2; r++) {
                    int cur = pre[l][j - 1] + suf[r][j + 1];
                    if (l == r) {
                        if (i == l) {
                            cur += (lft[j - 1] + rgt[j + 1] + (a[oi][j] == '*'));
                        } else {
                            if (a[oi][j] == '*') {
                                cur += lft[j - 1] + rgt[j + 1] + 1;
                            } else {
                                cur += (lft[j - 1] || rgt[j + 1] ? lft[j - 1] + rgt[j - 1] + 1 : 0);
                            }
                        }
                    } else {
                        if (a[oi][j] == '*') {
                            cur += (lft[j - 1] + rgt[j + 1] + 1);
                        } else {
                            if (i == l) {
                                cur += lft[j - 1] + (rgt[j + 1] ? 2 : 0);
                            } else {
                                cur += rgt[j + 1] + (lft[j - 1] ? 2 : 0);
                            }
                        }
                    }
                    ans = min(ans, cur);
                }
            }
        }
    }
    cout << ans << '\n';
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