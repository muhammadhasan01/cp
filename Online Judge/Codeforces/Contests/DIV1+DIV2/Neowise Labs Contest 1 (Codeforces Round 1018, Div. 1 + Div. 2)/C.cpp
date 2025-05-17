#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> h(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    auto computeCost = [&](bool isRow) {
        vector<long long> dp(2), ndp(2);
        dp[0] = 0;
        dp[1] = isRow ? a[0] : b[0];
        for (int idx = 0; idx < n - 1; idx++) {
            vector<bool> forbid(3);
            if (isRow) {
                for (int j = 0; j < n; j++) {
                    int d = h[idx][j] - h[idx + 1][j];
                    if (d >= -1 && d <= 1) {
                        forbid[d + 1] = true;
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    int d = h[i][idx] - h[i][idx + 1];
                    if (d >= -1 && d <= 1) {
                        forbid[d + 1] = true;
                    }
                }
            }
            ndp[0] = ndp[1] = INF;
            for (int cur = 0; cur < 2; cur++) {
                if (dp[cur] >= INF) {
                    continue;
                }
                for (int nxt = 0; nxt < 2; nxt++) {
                    int diff = nxt - cur;
                    if (diff >= -1 && diff <= 1 && forbid[diff + 1]) {
                        continue;
                    }
                    long long cost = dp[cur] + (nxt ? (isRow ? a[idx + 1] : b[idx + 1]) : 0LL);
                    ndp[nxt] = min(ndp[nxt], cost);
                }
            }
            dp.swap(ndp);
        }
        return min(dp[0], dp[1]);
    };

    long long rowCost = computeCost(true);
    long long colCost = computeCost(false);
    if (rowCost >= INF || colCost >= INF) {
        cout << -1 << '\n';
        return;
    }
    cout << rowCost + colCost << '\n';
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