#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> ones, zeros;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            zeros.emplace_back(i);
        } else {
            ones.emplace_back(i);
        }
    }
    int z = zeros.size();
    int o = ones.size();
    vector<vector<int>> dp(o + 1, vector<int>(z + 1, INF));
    vector<vector<int>> pre(o + 1, vector<int>(z + 1, INF));
    for (int j = 0; j <= z; j++) {
        dp[0][j] = 0;
        pre[0][j] = 0;
    }
    for (int i = 1; i <= o; i++) {
        int lft = i - 1;
        int rgt = o - i;
        int x = ones[i - 1];
        for (int j = lft + 1; j <= z - rgt; j++) {
            int y = zeros[j - 1];
            int dif = abs(x - y);
            dp[i][j] = dif + pre[i - 1][j - 1];
            pre[i][j] = min(pre[i][j - 1], dp[i][j]);
        }
    }
    cout << *min_element(dp[o].begin(), dp[o].end()) << '\n';
    
    return 0;
}