#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> s(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y, l] = s[i];
        cin >> x >> y >> l;
    }
    vector<tuple<int, int, int>> w(m);
    for (int i = 0; i < m; i++) {
        auto& [x, y, l] = w[i];
        cin >> x >> y >> l;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        auto [sx_1, sy_1, l] = s[i];
        int sy_2 = sy_1 + l;
        for (int j = 0; j < m; j++) {
            auto [wx_1, wy_1, l] = w[j];
            int wx_2 = wx_1 + l;
            if (wx_1 > sx_1 || wx_2 < sx_1) {
                continue;
            }
            if (sy_1 > wy_1 || sy_2 < wy_1) {
                continue;
            }
            int mx = sx_1;
            int my = wy_1;
            vector<pair<int, int>> points = {
                {sx_1, sy_1},
                {sx_1, sy_2},
                {wx_1, wy_1},
                {wx_2, wy_1}
            };
            long long res = INF;
            for (auto& [x, y] : points) {
                long long cur = 1LL * abs(x - mx) + 1LL * abs(y - my);
                res = min(res, cur);
            }
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';
    
    return 0;
}