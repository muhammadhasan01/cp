#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }
    sort(p.begin(), p.end());
    vector<pair<int, int>> pre(n);
    pre[0] = {p[0].second, p[0].second};
    for (int i = 1; i < n; i++) {
        int y = p[i].second;
        pre[i] = {min(pre[i - 1].first, y), max(pre[i - 1].second, y)};
    }
    vector<pair<int, int>> suf(n);
    suf[n - 1] = {p[n - 1].second, p[n - 1].second};
    for (int i = n - 2; i >= 0; i--) {
        int y = p[i].second;
        suf[i] = {min(suf[i + 1].first, y), max(suf[i + 1].second, y)};
    }

    auto can = [&](int i, int len) -> bool {
        int yl = p[i].second - len;
        int yr = p[i].second + len;
        {
            int xl = p[i].first - len;
            int l = 0, r = n - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (p[mid].first <= xl) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at != -1) {
                auto [ymin, ymax] = pre[at];
                if (ymin <= yl || ymax >= yr) {
                    return true;
                }
            }
        }
        {
            int xr = p[i].first + len;
            int l = 0, r = n - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (p[mid].first >= xr) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                } 
            }
            if (at != -1) {
                auto [ymin, ymax] = suf[at];
                if (ymin <= yl || ymax >= yr) {
                    return true;
                }
            }
        }
        return false;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = INF, res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(i, mid)) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }
        assert(res != -1);
        ans = max(ans, res);
    }
    cout << ans << '\n';

    return 0;
}