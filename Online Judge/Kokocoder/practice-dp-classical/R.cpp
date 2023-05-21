#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 2;
    for (int val = 1; val <= k; val++) {
        dp[val] = 2;
        for (int i = 0; i < n; i++) {
            int nval = val - a[i];
            if (nval < 0) {
                break;
            }
            if (dp[nval] == 2) {
                dp[val] = 1;
            }
        }
    }
    cout << (dp[k] == 1 ? "First" : "Second") << '\n';

    return 0;
}