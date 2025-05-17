#include <bits/stdc++.h>

using namespace std;

const int A = 5;
const int B = 4;
const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char cc;
            cin >> cc;
            a[i][j] = cc - '0';
        }
    }
    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1, pre = 0; j <= m; j++) {
            pre += a[i][j];
            dp[i][j] = dp[i - 1][j] + pre;
        }
    }

    auto getSub = [&](int x1, int y1, int x2, int y2) -> int {
        return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
    };

    auto getVal = [&](int st, int ed, int j) -> int {
        return getSub(st + 1, j, ed - 1, j) + (1 - a[st][j]) + (1 - a[ed][j]);
    };

    auto getBorder = [&](int st, int ed, int j) -> int {
        return (ed - st - 1) - getSub(st + 1, j, ed - 1, j);
    };

    int ans = INF;
    for (int st = 1; st <= n; st++) {
        for (int len = A; len <= n; len++) {
            int ed = st + len - 1;
            if (ed > n) {
                break;
            }
            int mn = INF;
            vector<int> pre(m + 1);
            for (int j = 1; j <= m; j++) {
                if (j - B + 1 >= 1) {
                    mn = min(mn, -pre[j - B + 1] + getBorder(st, ed, j - B + 1));
                }
                pre[j] = pre[j - 1] + getVal(st, ed, j);
                if (mn != INF) {
                    ans = min(ans, getBorder(st, ed, j) + pre[j - 1] + mn);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}