#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    vector<int> dp(n);
    vector<int> pre(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            auto [ri, li] = p[i];
            auto [rj, lj] = p[j];
            if (rj < li) {
                continue;
            }
            int minL = min(li, lj);
            dp[i] = max(dp[i], 2);
            int at = -1;
            {
                int l = 0, r = j - 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (p[mid].first < minL) {
                        l = mid + 1;
                        at = mid;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            if (at != -1) {
                dp[i] = max(dp[i], 2 + pre[at]);
            }
        }
        pre[i] = max(pre[i - 1], dp[i]);
    }
    cout << n - pre[n - 1] << '\n';
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