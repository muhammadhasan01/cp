#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    vector<int> h(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i] >> h[i];
    }
    for (int i = 1; i < m; i++) {
        int dif_d = abs(d[i] - d[i - 1]);
        int dif_h = abs(h[i] - h[i - 1]);
        if (dif_h > dif_d) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    auto can = [&](int x) -> bool {
        for (int i = 0; i < m; i++) {
            if (h[i] >= x) {
                return true;
            }
            int dif = x - h[i];
            for (int val : {d[i] + dif, d[i] - dif}) {
                if (val > n || val < 1) {
                    continue;
                }
                int pos = lower_bound(d.begin(), d.end(), val) - d.begin();
                if (pos < m) {
                    int dif_d = abs(val - d[pos]);
                    int dif_h = abs(x - h[pos]);
                    if (dif_h > dif_d) {
                        continue;
                    }
                }
                pos--;
                if (pos >= 0) {
                    int dif_d = abs(val - d[pos]);
                    int dif_h = abs(x - h[pos]);
                    if (dif_h > dif_d) {
                        continue;
                    }
                }
                return true;
            }
        }
        return false;
    };
    int l = 0, r = INF, ans = 0;
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
    
    return 0;
}