#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 105;
const int K = 505;

int dp[N][M][K];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        vector<int> cnt(K);
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            for (int val = x; val < K; val++) {
                cnt[val]++;
            }
            for (int k = 0; k < K; k++) {
                dp[i][j][k] = cnt[k] + dp[i - 1][j][k];
            }
        }
    }

    auto getMedian = [&](int a, int b, int c, int d) -> int {
        int len = (c - a + 1) * (d - b + 1);
        int need = (len + 1) / 2;
        int l = 0, r = K, ans = K;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int val = dp[c][d][mid] - dp[a - 1][d][mid] - dp[c][b - 1][mid] + dp[a - 1][b - 1][mid];
            if (val >= need) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    };

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << getMedian(a, b, c, d) << '\n';
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