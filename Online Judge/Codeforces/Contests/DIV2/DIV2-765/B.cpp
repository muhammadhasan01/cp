#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[i - 1] = make_pair(x, i);
    }
    sort(p.begin(), p.end());
    int ans = -1;
    for (int i = 1; i < n; i++) {
        auto [xl, l] = p[i - 1];
        auto [xr, r] = p[i];
        if (xl != xr) {
            continue;
        }
        int len = l + (n - r);
        ans = max(ans, len);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}