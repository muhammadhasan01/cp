#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
int n, w;
pair<int,int> a[N];
int f[N], dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    int mini = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n, greater<pair<int,int>>());

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i] = 0;
        } else if (i >= 2) {
            int pos = a[i].second;
            for (int j = i - 1; j >= 1; j--) {
                int cur = a[j].second;
                if (abs(pos - cur) <= w && a[j].first > a[i].first) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}
