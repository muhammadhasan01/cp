#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto can = [&](int x) -> bool {
        vector<int> last(k + 1);
        vector<long long> used(k + 1);
        for (int i = 1; i <= n; i++) {
            int cur = i - last[a[i]] - 1;
            used[a[i]] += 1LL * cur / (x + 1);
            last[a[i]] = i;
        }
        for (int c = 1; c <= k; c++) {
            int cur = n - last[c];
            used[c] += 1LL * cur / (x + 1);
            if (used[c] <= 1) {
                return true;
            }
        }
        return false;
    };

    int l = 0, r = n, ans = -1;
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