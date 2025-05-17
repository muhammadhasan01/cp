#include <bits/stdc++.h>

using namespace std;

const int D = 10;
const int F = 2;

long long DP(long long num) {
    if (num < 0) {
        return 0LL;
    }
    if (num == 0) {
        return 1LL;
    }
    vector<int> s;
    while (num > 0) {
        s.emplace_back(num % D);
        num /= 10;
    }
    reverse(s.begin(), s.end());
    int n = (int) s.size();
    vector dp(D, vector<long long>(F));
    dp[s[0]][1] = 1;
    for (int i = 1; i < s[0]; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        vector ndp(D, vector<long long>(2));
        // 0 - 0
        for (int x = 0; x < D; x++) {
            for (int y = 0; y < D; y++) {
                if (x == y) {
                    continue;
                }
                ndp[x][0] += dp[y][0];
            }
            if (x > 0) {
                ndp[x][0]++;
            }
        }
        // 1 - 0
        for (int x = 0; x < s[i]; x++) {
            if (x == s[i - 1]) {
                continue;
            }
            ndp[x][0] += dp[s[i - 1]][1];
        }
        // 1 - 1
        if (s[i] != s[i - 1]) {
            ndp[s[i]][1] += dp[s[i - 1]][1];
        }
        dp.swap(ndp);
    }
    long long ans = 1;
    for (int x = 0; x < D; x++) {
        for (int f = 0; f < F; f++) {
            ans += dp[x][f];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b;
    cin >> a >> b;
    cout << DP(b) - DP(a - 1) << '\n';
    
    return 0;
}