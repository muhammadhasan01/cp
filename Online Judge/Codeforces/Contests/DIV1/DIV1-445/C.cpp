#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 1e6 + 5;

long long n, k;
long long fact[N], invf[N];
long long dp[N], pre[N];

long long modpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
} 

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = invf[0] = 1;
    for (long long i = 1; i < N; i++) {
        fact[i] = (i * fact[i - 1]) % M;
        invf[i] = modpow(fact[i], M - 2, M);
    }
    cin >> n >> k;
    for (long long i = k + 1; i <= n; i++) {
        long long res = (fact[i - 2] * (i - k - 1)) % M;
        long long add = ((pre[i - 1] - pre[i - k - 1]) % M + M) % M;
        add = (add * (fact[i - 2])) % M;
        dp[i] = (res + add) % M;
        pre[i] = pre[i - 1] + (dp[i] * invf[i - 1]) % M;
        pre[i] %= M;
    }
    long long ans = pre[n] * fact[n - 1];
    cout << (ans % M + M) % M << '\n';

    return 0;
}