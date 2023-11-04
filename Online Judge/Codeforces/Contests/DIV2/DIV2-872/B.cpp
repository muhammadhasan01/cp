#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    int area = n * m;
    vector<long long> a(area);
    for (int i = 0; i < area; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = -INF;
    for (int rep = 0; rep < 2; rep++) {
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0) {
                    cur += (a[area - 1] - a[0]);
                } else if (j == 0) {
                    cur += (a[area - 1] - a[1]);
                } else {
                    cur += (a[area - 1] - min(a[0], a[1]));
                }
            }
        }
        ans = max(ans, cur);
        swap(a[0], a[1]);
    }
    for (int rep = 0; rep < 2; rep++) {
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0) {
                    cur += (a[area - 1] - a[0]);
                } else if (j == 0) {
                    cur += (a[area - 2] - a[0]);
                } else {
                    cur += (max(a[area - 1], a[area - 2]) - a[0]);
                }
            }
        }
        ans = max(ans, cur);
        swap(a[area - 1], a[area - 2]);
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