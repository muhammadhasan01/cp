#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long double INF = 1e16;
const long double eps = 1e-9;

int n;
pair<long double, long double> p[N];

bool can(long double R) {
    long double l = -INF, r = INF;
    for (int i = 1; i <= n; i++) {
        long double delta = 8 * R * p[i].second - 4 * p[i].second * p[i].second;
        if (delta < -eps) return false;
        long double D = (delta < 0 ? 0 : sqrt(delta)) / 2.0;
        l = max(l, p[i].first - D);
        r = min(r, p[i].first + D);
    }
    return !(l > r + eps);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    bool pos = false, neg = false;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        if (p[i].second > 0) {
            pos = true;
        } else {
            neg = true;
        }
    }
    if (pos == neg) {
        cout << -1 << '\n';
        return 0;
    }
    if (neg) {
        for (int i = 1; i <= n; i++) p[i].second = -p[i].second;
    }
    long double l = 0, r = INF;
    if (can(1)) {
        r = 1;
    } else {
        l = 1;
    }
    long double ans = INF;
    for (int i = 0; i < 150; i++) {
        long double mid = (l + r) / 2.0;
        if (can(mid)) {
            r = mid;
            ans = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}