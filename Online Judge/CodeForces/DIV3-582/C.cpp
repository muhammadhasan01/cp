#include <bits/stdc++.h>
using namespace std;

int q;
long long n, m;

long long dp[20][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 10; i++) {
        for (int j = 1; j <= 11; j++) {
            dp[i][j] = dp[i][j - 1] + (i * j) % 10;
        }
    }

    cin >> q;
    while (q--) {
        cin >> n >> m;
        long long k = n / m;
        cout << (k / 10) * dp[m % 10][10] + dp[m % 10][k % 10] << '\n';
    }

    return 0;
}
