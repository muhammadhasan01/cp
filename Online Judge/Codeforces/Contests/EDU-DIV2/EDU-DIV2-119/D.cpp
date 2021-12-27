#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = INF;
    for (int x = 0; x <= 2; x++) {
        for (int y = 0; y <= 2; y++) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                int mn = INF;
                for (int sx = 0; sx <= x; sx++) {
                    for (int sy = 0; sy <= y; sy++) {
                        int v = a[i] - sx - 2 * sy;
                        if (v >= 0 && v % 3 == 0) {
                            mn = min(mn, v / 3);
                        }
                    }
                }
                res = max(res, mn);
            }
            ans = min(ans, res + x + y);
        }
    }
    cout << ans << "\n";
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
