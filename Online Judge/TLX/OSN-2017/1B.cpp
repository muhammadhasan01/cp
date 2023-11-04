#include <bits/stdc++.h>

using namespace std;

long long INF = 2e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string useless;
    cin >> useless;
    int n;
    long long k;
    cin >> n >> k;
    string p, str;
    cin >> p >> str;
    vector<int> P;
    for (int i = 1; i <= n; i++) {
        if (str[i - 1] == '1') {
            P.emplace_back(i);
        }
    }
    int sum = 9 * n;
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, INF)); // (position, sum)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int pos : P) {
        vector<vector<long long>> ndp(n + 1, vector<long long>(sum + 1, INF));
        for (int i = 1; i <= n; i++) {
            int val = p[i - 1] - '0';
            int dist = abs(i - pos);
            for (int s = 0; s <= sum; s++) {
                ndp[i][s] = ndp[i - 1][s];
                if (s - val >= 0) {
                    ndp[i][s] = min(ndp[i][s], dp[i - 1][s - val] + dist);
                }
            }
        }
        dp.swap(ndp);
    }
    for (int s = sum; s >= 0; s--) {
        if (dp[n][s] <= k) {
            cout << s << '\n';
            return 0;
        }
    }
    assert(false);
    
    return 0;
}