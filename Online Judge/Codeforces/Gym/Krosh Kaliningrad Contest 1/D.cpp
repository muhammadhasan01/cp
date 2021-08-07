#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const int INF = 1e9;
const int MOD = 1e9+7;
 
int k, dp[N];
int c[N][N];
 
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
 
int product(int a, int b) {
    return (1ll * a * b) % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    c[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < i; j++) {
            add(dp[i], product(dp[j], c[i][j]));
        }
        add(dp[i], 1);
    }
    cout << dp[k] << '\n';

    return 0;
}