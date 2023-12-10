#include <bits/stdc++.h>

using namespace std;

const int K = 100;

void solve() {
    int n;
    cin >> n;
    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<double> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    auto F = [&](double k) -> double {
        double ret = 0;
        for (int i = 0; i < n; i++) {
            ret = max(ret, abs(x[i] - k) + t[i]);
        }
        return ret;
    };

    double l = 0, r = 1e8;
    for (int rep = 0; rep < K; rep++) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        if (F(m1) > F(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    cout << fixed << setprecision(9) << l << '\n';
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