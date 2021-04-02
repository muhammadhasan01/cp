#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int K = 13;

char s[N];
int dp[N][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> (s + 1);
    int n = strlen(s + 1);
    if (s[1] == '?') {
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
    } else {
        dp[1][(int) (s[1] - '0')] = 1;
    }
    for (int i = 2; i <= n; i++) {
        int num = s[i] - '0';
        for (int j = 0; j < 10; j++) {
            if (s[i] != '?' && num != j) continue;
            for (int k = 0; k < K; k++) {
                int res = (k * 10 + j) % K;
                dp[i][res] += dp[i - 1][k];
                dp[i][res] %= M;
            }
        }
    }
    cout << dp[n][5] << '\n';

    return 0;
}