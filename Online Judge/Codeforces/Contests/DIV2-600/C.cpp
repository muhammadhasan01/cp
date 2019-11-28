#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N];
long long ans, dp[N];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        ans += (1LL) * a[i] + dp[i % m];
        dp[i % m] += (1LL) * a[i];
        cout << ans << (i == n ? '\n' : ' ');
    }


    return 0;
}
