#include <bits/stdc++.h>

using namespace std;

map<int, vector<vector<int>>> dp;

vector<vector<int>> DP(int n) {
    if (dp.count(n)) {
        return dp[n];
    }
    if (n == 2) {
        return dp[2] = vector<vector<int>>{{1, 2}, {2, 1}};
    }
    vector<vector<int>> cur = DP(n - 1);
    for (auto& v : cur) {
        v.emplace_back(n);
    }
    cur.emplace_back(cur.back());
    swap(cur[n - 1][0], cur[n - 1][n - 1]);
    return dp[n] = cur;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans = DP(n);
    cout << ans.size() << '\n';
    for (auto v : ans) {
        int len = (int) v.size();
        for (int i = 0; i < len; i++) {
            cout << v[i] << " \n"[i == len - 1];
        }
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