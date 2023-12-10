#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        --c;
        pos[c].emplace_back(i);
    }
    for (int c = 0; c < n; c++) {
        vector<int> dp(K);
        for (int i : pos[c]) {
            vector<int> ndp = dp;
            int p = (i & 1);
            ndp[p] = max(ndp[p], ndp[1 - p] + 1);
            dp.swap(ndp);
        }
        cout << max(dp[0], dp[1]) << " \n"[c == n - 1];
    }
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