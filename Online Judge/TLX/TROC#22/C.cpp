#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> s(n + 2);
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        s[i] = cc - '0';
    }
    vector<vector<int>> f(k + 1, vector<int>(k + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> f[i][j];
        }
    }
    vector<int> pre(n + 1);
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + f[s[i - 1]][s[i]];
    }
    vector<int> dp(n + 1);
    vector<int> maxi(k + 1, -INF);
    maxi[s[1]] = 0;
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        for (int x = 1; x <= k; x++) {
            if (maxi[x] == -INF) {
                continue;
            }
            int cur = pre[i + 1] + maxi[x] - f[x][s[i + 1]];
            dp[i] = max(dp[i], cur);
        }
        maxi[s[i]] = max(maxi[s[i]], -pre[i] + dp[i - 1]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    
    return 0;
}