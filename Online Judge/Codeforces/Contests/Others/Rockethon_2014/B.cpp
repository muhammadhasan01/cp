#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; ; j += 2) {
            int k = i - j;
            if (k < 0) {
                break;
            }
            if (s[i] == s[k]) {
                dp[i] = max(dp[i], 1 + dp[k]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    
    return 0;
}