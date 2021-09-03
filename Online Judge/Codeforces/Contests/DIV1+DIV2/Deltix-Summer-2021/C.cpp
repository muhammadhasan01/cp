#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<long long> dp(n + 1);
    for (int i = 2; i <= n; i += 2) {
        vector<long long> d = c;
        long long take = min(d[i], d[i - 1]);
        dp[i] = take;
        if (d[i - 1] > d[i]) {
            continue;
        }
        long long cur = d[i] - take;
        long long sum = 0;
        for (int j = i - 2; j >= 1; j -= 2) {
            long long dd = min(d[j], d[j - 1]);
            d[j] -= dd;
            d[j - 1] -= dd;
            if (d[j - 1] > 0) {
                long long mn = min(d[j - 1], sum);
                d[j - 1] -= mn;
                sum -= mn;
                long long add = min(d[j - 1], cur);
                dp[i] += add;
                if (sum == 0) {
                    dp[i] += 1;
                }
                if (d[j - 1] > cur) {
                    break;
                }
                cur -= add;
            } else {
                sum += d[j];
                if (sum == 0) {
                    dp[i] += 1;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
    }
    cout << ans << '\n';

    return 0;
}