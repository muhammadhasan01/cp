#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 7;

int n;
int s[N];
char x[N];
bool dp[N][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        s[i] = (int) (cc - '0');
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    dp[n][0] = true;
    for (int i = n; i >= 1; i--) {
        for (int r = 0; r < K; r++) {
            int p = (10 * r) % K;
            int q = (10 * r + s[i]) % K;
            if (x[i] == 'T') {
                if (dp[i][p] || dp[i][q])
                    dp[i - 1][r] = true;
            } else if (x[i] == 'A') {
                if (dp[i][p] && dp[i][q])
                    dp[i - 1][r] = true;
            }
        }
    }
    cout << (dp[0][0] ? "Takahashi" : "Aoki") << '\n';

    return 0;
}