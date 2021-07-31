#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= max(1, i - k); j--) {
            long long cur = 1LL * i * j - k * (a[i] | a[j]);
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}