#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int K = 5;
const int B = (1 << (K + 1));
const int vals[] = {1, 10, 100, 1000, 10000};

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int n = s.length();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] - 'A');
    }
    vector<vector<long long>> dp(B, vector<long long>(2, -INF));
    {
        dp[(1 << a[0])][0] = vals[a[0]];
        for (int i = 0; i < K; i++) {
            dp[(1 << i)][1] = vals[i];
        }
    }
    for (int i = 1; i < n; i++) {
        vector<vector<long long>> ndp(B, vector<long long>(2, -INF));
        for (int mask = 0; mask < B; mask++) {        
            int nmask = (mask | (1 << a[i]));
            int add = vals[a[i]];
            for (int j = a[i] + 1; j < K; j++) {
                if (mask & (1 << j)) {
                    add *= -1;
                    break;
                }
            }
            if (dp[mask][0] != -INF) {
                ndp[nmask][0] = max(ndp[nmask][0], dp[mask][0] + add);
            }
            if (dp[mask][1] != -INF) {
                ndp[nmask][1] = max(ndp[nmask][1], dp[mask][1] + add);
            }
            for (int j = 0; j < K; j++) {
                int cmask = (mask | (1 << j));
                int curadd = vals[j];
                for (int k = j + 1; k < K; k++) {
                    if (mask & (1 << k)) {
                        curadd *= -1;
                        break;
                    }
                }
                if (dp[mask][0] != -INF) {
                    ndp[cmask][1] = max(ndp[cmask][1], dp[mask][0] + curadd);
                }
            }
        }
        dp.swap(ndp);
    }
    long long ans = -INF;
    for (int mask = 0; mask < B; mask++) {
        for (int i = 0; i < 2; i++) {
            ans = max(ans, dp[mask][i]);
        }
    }
    cout << ans << '\n';
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