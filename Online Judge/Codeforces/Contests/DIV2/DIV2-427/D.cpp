#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const int M = 1e9 + 7;
const int primes[2] = {29, 31};

char s[N];
int n;
int dp[N][N];
long long prec[N][2];
long long pre[N][2];
long long suf[N][2];
long long ans[N];

bool checkPalindrome(int x, int y) {
    if (x == y) return true;
    if (x == y - 1) return s[x] == s[y];
    if (x == y - 2) return s[x] == s[y];
    int lenz = (y - x + 1) / 2;
    int rx = x + lenz - 1;
    int ly = y - lenz + 1;
    for (int it = 0; it < 2; it++) {
        long long pval = pre[rx][it] - (x == 0 ? 0 : pre[x - 1][it]);
        pval = (pval % M + M) % M;
        long long sval = suf[ly][it] - suf[y + 1][it];
        sval = (sval % M + M) % M;
        // degree of pval = x -> add n - x => n
        // degree of sval = n - y - 1 -> add y + 1 => n
        // make them equal
        pval = (pval * prec[n - x][it]) % M;
        sval = (sval * prec[y + 1][it]) % M;
        if (pval != sval) return false;
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = strlen(s);
    prec[0][0] = prec[0][1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            prec[i][j] = (prec[i - 1][j] * primes[j]) % M;
        }
    }
    for (int i = 0; i < n; i++) {
        long long val = (s[i] - 'a');
        for (int j = 0; j < 2; j++) {
            if (i > 0) pre[i][j] = pre[i - 1][j];
            pre[i][j] = (pre[i][j] + prec[i][j] * val) % M;
        }
    }
    for (int i = n - 1, p = 0; i >= 0; i--, p++) {
        long long val = (s[i] - 'a');
        for (int j = 0; j < 2; j++) {
            suf[i][j] = suf[i + 1][j];
            suf[i][j] = (suf[i][j] + prec[p][j] * val) % M;
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            int j = i + len - 1;
            if (j >= n) break;
            if (len == 1) {
                dp[i][j] = 1;
            } else if (len == 2 || len == 3) {
                dp[i][j] = (s[i] == s[j] ? 2 : 0);
            } else {
                if (checkPalindrome(i, j)) {
                    dp[i][j] = 1;
                    int mid = (i + j) >> 1;
                    int sub = 0;
                    if ((j - i + 1) & 1) sub++;
                    if (dp[i][mid - sub] == dp[mid + 1][j]) {
                        dp[i][j] = 1 + dp[mid + 1][j];
                    }
                }
            }
            ans[dp[i][j]]++;
        }
    }
    for (int i = n; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}