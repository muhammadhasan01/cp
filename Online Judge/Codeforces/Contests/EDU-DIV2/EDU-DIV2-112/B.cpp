#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    long long W, H;
    cin >> W >> H;
    vector<long long> x(2), y(2);
    for (int i = 0; i < 2; i++) {
        cin >> x[i] >> y[i];
    }
    long long w, h;
    cin >> w >> h;
    if (w <= x[0] || h <= y[0] || x[1] + w <= W || y[1] + h <= H) {
        cout << fixed << setprecision(9) << 0.0 << '\n';
        return;
    }
    long long res = INF;
    long long dx = w - x[0];
    long long dy = h - y[0];
    long long dp = x[1] - (W - w);
    long long dq = y[1] - (H - h);
    if (x[1] + dx <= W) {
        res = min(res, dx);
    }
    if (x[0] - dp >= 0) {
        res = min(res, dp);
    }
    if (y[1] + dy <= H) {
        res = min(res, dy);
    }
    if (y[0] - dq >= 0) {
        res = min(res, dq);
    }
    if (res == INF) {
        cout << -1 << '\n';
        return;
    }
    cout << fixed << setprecision(9) << (long double) res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}