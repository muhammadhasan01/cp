#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 5;

int tc;
int n;
int p[N], pos[N];

void solve() {
    cin >> n;
    n = 2 * n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    int leftz = n;
    vector<int> valz;
    for (int i = n; i >= 1; i--) {
        int cur = pos[i];
        int sz = leftz - cur + 1;
        if (sz <= 0) continue;
        leftz = cur - 1;
        if (sz > n / 2) {
            cout << "NO" << '\n';
            return;
        }
        valz.emplace_back(sz);
    }
    int len = valz.size();
    vector<vector<bool>> dp(len + 1, vector<bool>(n / 2 + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (valz[i - 1] <= j && dp[i - 1][j - valz[i - 1]]) {
                dp[i][j] = 1;
            }
        }
    }
    cout << (dp[len][n / 2] ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}