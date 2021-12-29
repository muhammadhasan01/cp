#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    auto can = [&](int x) -> bool {
        vector<int> donate(n);
        for (int i = n - 1; i >= 0; i--) {
            int cur = h[i] + donate[i];
            if (cur < x) {
                return false;
            }
            if (i < 2) {
                continue;
            }
            int cst = max(0, min(h[i] + donate[i] - x, h[i]) / 3);
            donate[i - 1] += cst;
            donate[i - 2] += 2 * cst;
        }
        return true;
    };
    int l = 1, r = INF, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
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