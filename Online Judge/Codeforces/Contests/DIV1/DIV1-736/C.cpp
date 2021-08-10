#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 4e6 + 5; 
const int K = 3;

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

int n, q;
long long dp[N][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> q;
    for (int j = 0; j < K; j++) {
        dp[0][j] = n;
    }
    long long inv3 = inv(3);
    int m = 3 * n;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = (C(m, i + 1) - (2 * dp[i - 1][0] + dp[i - 1][1]) % M + M) % M;
        dp[i][0] = (dp[i][0] * inv3) % M;
        for (int j = 1; j < K; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % M;
        }
    }
    while (q--) {
        int x;
        cin >> x;
        long long ans = (dp[x][0] + C(3 * n, x)) % M;
        cout << ans << '\n';
    }

    return 0;
}