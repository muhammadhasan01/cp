#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;
const long long M = 1e9 + 7;
const int primes[] = {29, 31};

string s;
int n;
int dp[N];
long long pre[N][1];
long long suf[N][1];
long long precompute[N][1];
long long ans;

long long mmod(long long x) {
    return (x % M + M) % M;
}

bool check(int len) {
    int lenz = (len - 1) / 2;
    int pos = lenz + 1 + (len % 2 == 0);
    int deg = n - pos - 1;
    for (int i = 0; i < 1; i++) {
        long long pref = mmod(pre[lenz][i] * precompute[(n - 1) - lenz][i]);
        long long suff = mmod((suf[pos][i] - suf[pos + lenz + 1][i]) * precompute[(n - 1) - deg][i]);
        if (pref != suff) return false;
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    precompute[0][0] = precompute[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1; j++) {
            precompute[i][j] = (primes[j] * precompute[i - 1][j]) % M;
        }
    }
    for (int i = 0; i < n; i++) {
        long long cur = s[i];
        for (int j = 0; j < 1; j++) {
            if (i > 0) pre[i][j] = pre[i - 1][j];
            pre[i][j] += cur * precompute[i][j];
            pre[i][j] %= M;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        long long cur = s[i];
        for (int j = 0; j < 1; j++) {
            suf[i][j] = suf[i + 1][j];
            suf[i][j] += cur * precompute[(n - 1) - i][j];
            suf[i][j] %= M;
        }
    }
    dp[0] = 1;
    ans = 1;
    for (int i = 1; i < n; i++) {
        int j = (i - 1) / 2;
        if (check(i)) {
            dp[i] = 1 + dp[j];
            ans += dp[i];
        }
    }
    cout << ans << '\n';

    return 0;
}