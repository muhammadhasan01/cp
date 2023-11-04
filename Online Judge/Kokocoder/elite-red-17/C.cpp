#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    auto getMinMax = [&](int k) -> pair<int, int> {
        if (k <= s) {
            return make_pair(0, k);
        }
        int x = s;
        int y = k - s;
        if (x > y) {
            swap(x, y);
        }
        return make_pair(x, y);
    };

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = getMinMax(a[i]);
    }
    vector<long long> dp(2);
    for (int i = 1; i < n; i++) {
        vector<long long> ndp(2);
        if (i == 1) {
            ndp[0] = 1LL * a[i - 1] * p[i].first;
            ndp[1] = 1LL * a[i - 1] * p[i].second;
        } else if (i == n - 1) {
            ndp[0] = ndp[1] = min(dp[0] + 1LL * p[i - 1].second * a[i], dp[1] + 1LL * p[i - 1].first * a[i]);
        } else {
            ndp[0] = min(dp[0] + 1LL * p[i - 1].second * p[i].first, dp[1] + 1LL * p[i - 1].first * p[i].first);
            ndp[1] = min(dp[0] + 1LL * p[i - 1].second * p[i].second, dp[1] + 1LL * p[i - 1].first * p[i].second);
        }
        dp.swap(ndp);
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}