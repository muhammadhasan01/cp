#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<double, double>> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }
    auto dist = [&](pair<double, double>& lhs, pair<double, double>& rhs) {
        auto [x1, y1] = lhs;
        auto [x2, y2] = rhs;
        double dx = abs(x1 - x2);
        double dy = abs(y1 - y2);
        return sqrt(dx * dx + dy * dy);
    };
    vector<vector<double>> dp_0(n, vector<double>(n));
    vector<vector<double>> dp_1(n, vector<double>(n));
    for (int i = 2; i <= n; i++) {
        for (int l = 0; l < n; l++) {
            int r = (l + i - 1) % n;
            int nl = (l + 1) % n;
            int br = (r - 1 + n) % n;
            dp_0[l][r] = max(dp_0[nl][r] + dist(p[nl], p[l]), dp_1[nl][r] + dist(p[r], p[l]));
            dp_1[l][r] = max(dp_0[l][br] + dist(p[l], p[r]), dp_1[l][br] + dist(p[br], p[r]));
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp_0[i][(i + n - 1) % n]);
        ans = max(ans, dp_1[i][(i + n - 1) % n]);
    }
    cout << fixed << setprecision(9) << ans << '\n';
    
    return 0;
}