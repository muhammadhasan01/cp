#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long double VMAX = 3e8;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll l;
    cin >> n >> l;
    vector<ll> d(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    long double Tinf = 0.0L;
    for (int i = 0; i < n; i++) {
        Tinf = max(Tinf, (long double)d[i]) + w[i];
    }
    if (Tinf >= l) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    auto feasible = [&](long double v) -> bool {
        long double t = 0.0L;
        long double pos = 0.0L;
        for (int i = 0; i < n; i++) {
            long double travel = (d[i] - pos) / v;
            long double arrive = t + travel;
            if (arrive < d[i]) {
                arrive = d[i];
            }
            if (arrive > l) {
                return false;
            }
            t = arrive + w[i];
            if (t > l) {
                return false;
            }
            pos = d[i];
        }
        long double finalRun = (l - pos) / v;
        return (t + finalRun) <= l;
    };

    if (!feasible(VMAX)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    long double lo = 0.0L, hi = VMAX;
    for (int iter = 0; iter < 100; iter++) {
        long double mid = (lo + hi) / 2;
        if (feasible(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(10) << (double) hi << "\n";

    return 0;
}
