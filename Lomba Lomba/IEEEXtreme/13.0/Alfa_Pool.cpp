#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const ll M = 1e9 + 7;
int n;
ll dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 1;
    dp[1] = dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= N - 5; i++) {
        ll cur = 0;
        for (ll j = 1; j <= i; j++) {
            cur += j;
            if (i - cur <= 0) break;
            dp[i] += dp[i - cur] % M;
        }
        dp[i]++;
    }

    cin >> n;
    while (n--) {
        int b;
        cin >> b;
        cout << (dp[b] % M + M) % M << '\n';
    }

    return 0;
}
