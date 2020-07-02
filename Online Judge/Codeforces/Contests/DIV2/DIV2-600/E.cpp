#include <bits/stdc++.h>

using namespace std;

const int N = 1e2;
const int M = 1e5 + 5;
int n, m;
int le[N], ri[N];
int dp[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, s;
        cin >> x >> s;
        le[i] = max(0, x - s);
        ri[i] = min(m, x + s);
    }
    for (int i = m - 1; i >= 0; i--) {
        dp[i] = (m - i);
        for (int j = 1; j <= n; j++) {
            int l = le[j], r = ri[j];

            if (l <= i + 1 && i + 1 <= r) {
                dp[i] = dp[i + 1];
                break;
            }

            if (i < l) {
                int cost = (l - i - 1);
                int pos = min(m, r + cost);
                dp[i] = min(dp[i], dp[pos] + cost);
            }
        }
    }

    cout << dp[0] << '\n';

    return 0;
}
