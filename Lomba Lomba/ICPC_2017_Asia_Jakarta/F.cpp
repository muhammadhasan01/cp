#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;
const double TERM = -1.0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<double>> dp(N, vector<double>(N, TERM));

    function<double(int, int)> DP = [&](int x, int y) {
        if (x < 0 || y < 0) {
            return 0.0;
        }
        if (x == 0 && y == 0) {
            return 0.0;
        }
        if (dp[x][y] != TERM) {
            return dp[x][y];
        }
        return dp[x][y] = (DP(x - 1, y + 1) * x + DP(x, y - 1) * y + 1) / (x + y);
    };

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(n + 1);
        for (int i = 0; i < k; i++) {
            int num;
            cin >> num;
            cnt[num]++;
        }
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                ++x;
            } else if (cnt[i] == 1) {
                ++y;
            }
        }
        cout << fixed << setprecision(9) << DP(x, y) * n << '\n';   
    }
    
    return 0;
}