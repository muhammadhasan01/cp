#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 5; 

long long fact[N];
long long invf[N];

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

long long inv(long long x) {
    return modpow(x, M - 2);
}

long long C(int a, int b) {
    if (a < b) return 0;
    long long ret = (fact[a] * invf[b]) % M;
    ret = (ret * invf[a - b]) % M;
    return ret;
}

void init() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        invf[i] = inv(fact[i]);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    long long same = 0;
    for (int i = 0; i < n; i += 2) {
        same = (same + C(n, i)) % M;
    }
    if (n % 2 == 1) {
        same = (same + 1) % M;
    }
    vector<long long> dp(k + 1);
    bool even = (n % 2 == 0);
    long long num = modpow(2, n);
    num = (num % M + M) % M;
    dp[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        if (even) {
            int j = k - i;
            long long cur = (dp[i - 1] * modpow(num, j)) % M;
            ans = (ans + cur) % M;
        }
        dp[i] = (dp[i - 1] * same) % M;
    }
    ans = (ans + dp[k]) % M;
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}