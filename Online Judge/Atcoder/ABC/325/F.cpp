#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;
const int T = 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<long long> L(T), C(T), K(T);
    for (int i = 0; i < T; i++) {
        cin >> L[i] >> C[i] >> K[i];
    }
    vector<long long> dp(K[0] + 1, INF);
    dp[0] = 0LL;
    for (int i = 0; i < n; i++) {
        vector<long long> ndp(K[0] + 1, INF);
        for (int take = 0; take <= K[0]; take++) {
            long long cur = max(0LL, d[i] - 1LL * take * L[0]);
            long long need = (cur + L[1] - 1) / L[1];
            for (int bef = 0; bef <= K[0]; bef++) {
                if (take + bef > K[0]) {
                    break;
                }
                ndp[take + bef] = min(ndp[take + bef], dp[bef] + need);
            }
        }
        dp.swap(ndp);
    }
    long long ans = INF;
    for (int take = 0; take <= K[0]; take++) {
        if (dp[take] > K[1]) {
            continue;
        }
        ans = min(ans, 1LL * take * C[0] + 1LL * dp[take] * C[1]);
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}