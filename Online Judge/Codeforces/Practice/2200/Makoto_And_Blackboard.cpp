// Pasti AC nih :)
#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 1e2 + 5;
const int K = 1e4 + 5;

long long n, k;
long long pre[N];
long long dp[K][N];

long long fastpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) {
            ret = (ret * x) % p;
        }
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
}

long long solve(const pair<long long, int>& p) {
    long long ret = 0;
    int cnt = p.second;
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j <= cnt; j++) {
        dp[1][j] = pre[cnt + 1];
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= cnt; j++) {
            for (int x = j; x <= cnt; x++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][x] * pre[x + 1]) % M;
            }
        }
    }
    long long prime = p.first;
    long long cur = 1;
    for (int j = 0; j <= cnt; j++) {
        ret = (ret + cur * dp[k][j]) % M;
        cur = (cur * prime) % M;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<pair<long long, int>> primes;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            primes.push_back(make_pair(i, cnt));
        }
    }
    if (n > 1) {
        primes.push_back(make_pair(n, 1));
    }
    for (int i = 1; i < N; i++) {
        pre[i] = fastpow(i, M - 2, M);
    }
    long long ans = 1;
    for (auto& e : primes) {
        ans = (ans * solve(e)) % M;
    }
    cout << ans << '\n';

    return 0;
}