#include <bits/stdc++.h>

using namespace std;

int tc;
long long d, m;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> d >> m;
        vector<long long> v;
        for (int i = 0; i <= 30; i++) {
            long long cur = (1LL << i);
            long long nxt = min(d, (1LL << (i + 1)) - 1LL);
            if (cur <= nxt)
                v.push_back(nxt - cur + 1); 
        }
        int len = v.size();
        vector<long long> dp(len);
        long long ans = 0;
        for (int i = 0; i < len; i++) {
            dp[i] = v[i] % m;
            for (int j = 0; j < i; j++) {
                dp[i] = (dp[i] + v[i] * dp[j]) % m;
            }
            ans = (ans + dp[i]) % m;
        }
        cout << ans << '\n';
    }
    
    return 0;
}