#include <bits/stdc++.h>

using namespace std;

void solve() {
    long double px, py;
    vector<long double> X(2), Y(2);
    cin >> px >> py;
    for (int i = 0; i < 2; i++) {
        cin >> X[i] >> Y[i];
    }
    vector<long double> dist(5);
    for (int i = 0; i < 2; i++) {
        dist[i] = (X[i] - px) * (X[i] - px) + (Y[i] - py) * (Y[i] - py);
    }
    dist[2] = ((X[0] - X[1]) * (X[0] - X[1]) + (Y[0] - Y[1]) * (Y[0] - Y[1])) / 4.0;
    dist[3] = X[0] * X[0] + Y[0] * Y[0];
    dist[4] = X[1] * X[1] + Y[1] * Y[1];

    auto can = [&](long double w) -> bool {
        w = w * w;
        if (w >= dist[0] && w >= dist[3]) {
            return true;
        }
        if (w >= dist[1] && w >= dist[4]) {
            return true;
        }
        if (w >= dist[3] && w >= dist[1] && w >= dist[2]) {
            return true;
        }
        if (w >= dist[4] && w >= dist[0] && w >= dist[2]) {
            return true;
        }
        return false;
    };

    long double l = 0, r = 1e5, ans = 0;
    for (int rep = 0; rep < 60; rep++) {
        long double mid = (l + r) / 2.0;
        if (can(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(9) << ans << '\n';
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