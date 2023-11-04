#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto can = [&](int k) -> bool {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (a[i] <= k) {
                continue;
            }
            if (a[i] >= n - k + 1) {
                continue;
            }
            v.emplace_back(a[i]);
        }
        return v.empty() || is_sorted(v.begin(), v.end());
    };

    int l = 0, r = n / 2, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
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