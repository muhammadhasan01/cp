#include <bits/stdc++.h>

using namespace std;

const long long M = 998244353;
const int N = 22;
const int K = 10;

long long dp[N][(1 << K)][2];
long long dps[N][(1 << K)][2];
long long pw10[N];

long long solve(const string& val, int k) {
    int len = val.size();
    for (int i = 0; i <= len; i++) {
        for (int mask = 0; mask < (1 << K); mask++) {
            for (int equal = 0; equal < 2; equal++) {
                dp[i][mask][equal] = 0;
                dps[i][mask][equal] = 0;
            }
        }
    }
    dp[0][0][1] = 1;
    for (int i = 1; i <= len; i++) {
        int num = val[i - 1] - '0';
        for (int mask = 0; mask < (1 << K); mask++) {
            for (int x = (i == 1); x < K; x++) {
                int nmask = mask | (1 << x);
                for (int equal = 0; equal < 2; equal++) {
                    if (equal == 1 && x > num) {
                        continue;
                    }
                    long long cnt = dp[i - 1][mask][equal];
                    if (cnt == 0) {
                        continue;
                    }
                    int flag = (equal && x == num);
                    long long mul = (pw10[len - i] * x) % M;
                    mul = (mul * (cnt % M)) % M;
                    long long sum = (dps[i - 1][mask][equal] + mul) % M;
                    dp[i][nmask][flag] += cnt;
                    dps[i][nmask][flag] = (dps[i][nmask][flag] + sum) % M;
                }
            }
        }
    }
    long long ans = 0;
    for (int mask = 0; mask < (1 << K); mask++) {
        if (__builtin_popcount(mask) > k) {
            continue;
        }
        ans = (ans + dps[len][mask][0]) % M;
        ans = (ans + dps[len][mask][1]) % M;
    }
    return ans;
}

long long calc(long long val, int k) {
    int len = to_string(val).size();
    long long ans = 0;
    for (int l = 1; l < len; l++) {
        ans = (ans + solve(string(l, '9'), k)) % M;
    }
    ans = (ans + solve(to_string(val), k)) % M;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pw10[0] = 1;
    for (int i = 1; i < N; i++) {
        pw10[i] = (1LL * 10 * pw10[i - 1]) % M;
    }
    long long l, r;
    int k;
    cin >> l >> r >> k;
    long long ans = calc(r, k) - calc(l - 1, k);
    cout << (ans % M + M) % M << '\n';

    return 0;
}