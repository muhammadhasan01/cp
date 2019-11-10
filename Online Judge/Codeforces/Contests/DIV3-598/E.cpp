#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const ll INF = 1e18;
int n;
pair<ll,int> a[N];
ll dp[N];
int pos[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);

    dp[1] = dp[2] = INF;
    for (int i = 3; i <= 5; i++) {
        dp[i] = a[i].first - a[1].first;
        pos[i] = 1;
    }
    for (int i = 6; i <= n; i++) {
        dp[i] = INF;
    }

    for (int i = 6; i <= n; i++) {
        for (int j = 2; j <= 4; j++) {
            int k = i - j;
            if (k < 1) break;
            ll dif = a[i].first - a[k].first;
            if (dp[i] > dp[k - 1] + dif) {
                dp[i] = dp[k - 1] + dif;
                pos[i] = k;
            }
        }
    }

    int len = 0, cur = n;
    while (cur > 0) {
        ++len;
        for (int i = pos[cur]; i <= cur; i++) {
            ans[a[i].second] = len;
        }
        cur = pos[cur] - 1;
    }

    cout << dp[n] << " " << len << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
