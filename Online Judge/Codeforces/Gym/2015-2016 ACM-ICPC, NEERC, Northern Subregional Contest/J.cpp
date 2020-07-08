#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int INF = 2e9;

int n;
int p[N], d[N];
long long t;
long long dp[N];

bool can(int x) {
    multiset<long long> ms;
    ms.emplace(dp[n]);
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = *ms.begin() + (1LL) * d[i];
        ms.emplace(dp[i]);
        if (i + x <= n) {
            ms.erase(ms.find(dp[i + x]));
        }
    }
    return (dp[1] <= t);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);
    cin >> n >> t;
    t -= (n - 1);
    for (int i = 1; i <= n - 1; i++) {
        cin >> p[i];
    }
    for (int i = 2; i <= n - 1; i++) {
        cin >> d[i];
    }
    int l = 1, r = n - 1, pos = n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int ans = INF;
    for (int i = pos; i <= n - 1; i++) {
        ans = min(ans, p[i]);
    }
    cout << ans << '\n';

    return 0;
}