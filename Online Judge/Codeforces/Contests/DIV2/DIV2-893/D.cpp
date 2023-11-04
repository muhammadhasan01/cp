#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> pre(n + 2, vector<int>(k + 1));
    {
        deque<int> zeroes = {0};
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                zeroes.emplace_front(i);
            }
            for (int j = 0; j <= k; j++) {
                int sz = (int) zeroes.size();
                int maxlen = i - zeroes[min(j, sz - 1)];
                pre[i][j] = max(pre[i - 1][j], maxlen);
            }
        }
    }
    vector<vector<int>> suf(n + 2, vector<int>(k + 1));
    {
        deque<int> zeroes = {n + 1};
        for (int i = n; i >= 1; i--) {
            if (s[i] == '0') {
                zeroes.emplace_front(i);
            }
            for (int j = 0; j <= k; j++) {
                int sz = (int) zeroes.size();
                int maxlen = zeroes[min(j, sz - 1)] - i;
                suf[i][j] = max(suf[i + 1][j], maxlen);
            }
        }
    }
    // dp[l0] = max l1 possible
    vector<int> dp(n + 1, -1);
    for (int r = 1; r <= n; r++) {
        dp[0] = max({dp[0], pre[r][k], suf[r][k]});
        for (int l = r, cur = k; l >= 1; l--) {
            if (s[l] == '1') {
                --cur;
            }
            if (cur < 0) {
                break;
            }
            int len = r - l + 1;
            dp[len] = max({dp[len], pre[l - 1][cur], suf[r + 1][cur]});
        }
    }
    for (int a = 1; a <= n; a++) {
        long long ans = 0;
        for (int l0 = 0; l0 <= n; l0++) {
            if (dp[l0] == -1) {
                continue;
            }
            ans = max(ans, 1LL * a * l0 + dp[l0]);
        }
        cout << ans << " \n"[a == n];
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