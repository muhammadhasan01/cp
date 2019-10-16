#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;
const ll inf = 2e18;
int q, n;
pair<int,ll> a[N];
long long dp[3][5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        for (int it = 1; it <= n; it++) {
            int i = (it & 1);
            if (it == 1) {
                for (int j = 1; j <= 3; j++) {
                    dp[i][j] = (1LL) * (j - 1) * a[i].second;
                }
            } else {
                for (int j = 1; j <= 3; j++) {
                    long long cur = inf;
                    for (int k = 1; k <= 3; k++) {
                        if (a[it - 1].first + (1LL) * k == a[it].first + (1LL) * j) continue;
                        cur = min(cur, dp[(i ^ 1)][k] + (1LL) * (j - 1) * a[it].second);
                    }
                    dp[i][j] = cur;
                }
            }
        }
        long long ans = inf;
        for (int i = 1; i <= 3; i++) ans = min(ans, dp[(n & 1)][i]);
        cout << ans << '\n';
    }

    return 0;
}
