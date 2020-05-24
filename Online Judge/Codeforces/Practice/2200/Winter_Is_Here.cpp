#include <bits/stdc++.h>

using namespace std;

const int M = 1e6 + 5;
const long long MOD = 1e9 + 7;

int n;
long long cnt[M];
long long pre[M];
long long dp[M];

long long func(long long x) {
    return (x * pre[x - 1]) % MOD;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0] = 1;
    for (int i = 1; i < M; i++) {
        pre[i] = (pre[i - 1] << 1) % MOD;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 2; i < M; i++) {
        for (int j = (i << 1); j < M; j += i) {
            cnt[i] += cnt[j];
        }
    }
    long long ans = 0;
    for (int i = M - 1; i >= 2; i--) {
        dp[i] = func(cnt[i]);
        for (int j = (i << 1); j < M; j += i) {
            dp[i] = (dp[i] + MOD - dp[j]) % MOD;
        }
        ans = (ans + dp[i] * i) % MOD;
    }
    cout << ans << '\n';

    return 0;
}