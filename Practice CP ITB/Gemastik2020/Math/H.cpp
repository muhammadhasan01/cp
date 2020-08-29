#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9 + 7;

int n, k;
int dp[N];
int lp[N];
int prime[N];

int fastpow(long long x, int y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

void upd(int& x, int y) {
    x = (x + y) % M;
    x = (x % M + M) % M;
}

int get(int x) {
    int ret = 0;
    for (int i = 1; i <= x; i++) {
        if (lp[i] != 1) continue;
        if (prime[i] % 2 == 0) {
            upd(ret, dp[x / i]);
        } else {
            upd(ret, -dp[x / i]);
        }
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    iota(lp + 1, lp + 1 + k, 1);
    for (int i = 2; i <= k; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= k; j += i) {
            prime[j]++;
            lp[j] /= i;
        }
    }
    for (int i = 1; i <= k; i++) {
        dp[i] = fastpow(i, n);
    }
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        long long cur = ((1LL) * i * get(k / i)) % M;
        ans = (ans + cur) % M;
    }
    cout << (ans % M + M) % M << '\n';

    return 0;
}