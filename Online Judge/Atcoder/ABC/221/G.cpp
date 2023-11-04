#include <bits/stdc++.h>

using namespace std;

const int MAX = 3600005;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    vector<int> s(2);
    s[0] = a - b;
    s[1] = a + b;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += d[i];
    }
    for (int i = 0; i < 2; i++) {
        if (abs(s[i]) > abs(sum) || abs(s[i] + sum) % 2 == 1) {
            cout << "No" << '\n';
            return 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        s[i] = (s[i] + sum) / 2;
    }
    vector<bitset<MAX>> dp(n + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] | (dp[i - 1] << d[i]));
    }
    if (!dp[n][s[0]] || !dp[n][s[1]]) {
        cout << "No" << '\n';
        return 0;
    }
    vector<char> dir = {'L', 'D', 'U', 'R'};
    string ans = "";
    for (int i = n - 1; i >= 0; i--) {
        int x = 0;
        for (int j = 0; j < 2; j++) {
            if (!dp[i][s[j]]) {
                s[j] -= d[i + 1];
                x += (1 << j);
            }
        }
        ans += dir[x];
    }
    reverse(ans.begin(), ans.end());
    cout << "Yes" << '\n';
    cout << ans << '\n';
    
    return 0;
}