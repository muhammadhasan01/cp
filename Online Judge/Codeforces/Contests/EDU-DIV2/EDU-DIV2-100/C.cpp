#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> t(n + 1), x(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i];
    }
    t[n] = INF;
    long long st = 0, sx = 0;
    long long et = 0, ex = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (et <= t[i]) {
            long long nt = t[i] + abs(x[i] - ex);
            if (t[i + 1] >= nt) {
                ++ans;
            }
            st = t[i];
            et = nt;
            sx = ex;
            ex = x[i];
        } else {
            long long dir = (ex >= sx ? 1 : -1);
            long long lx = sx + dir * (t[i] - st);
            long long rx = sx + dir * (min(et, t[i + 1]) - st);
            if (min(lx, rx) <= x[i] && x[i] <= max(lx, rx)) {
                ++ans;
            }
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