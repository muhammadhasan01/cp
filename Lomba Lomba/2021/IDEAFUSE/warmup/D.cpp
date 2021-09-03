#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y] = p[i];
        cin >> x >> y;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            auto& [xi, yi] = p[i];
            auto& [xj, yj] = p[j];
            ans = max(ans, abs(xi - xj));
            ans = max(ans, abs(yi - yj));
        }
    }
    cout << ans * ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case #" << T << ": ";
        solve();
    }
    
    return 0;
}