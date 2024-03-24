#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);
const long double EPS = 1e-10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long double> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        int parity = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            long double dx = abs(x[i] - x[j]);
            long double dy = abs(y[i] - y[j]);
            long double dist = sqrtl(dx * dx + dy * dy);
            if (dist + r[i] - r[j] <= EPS) {
                parity ^= 1;
                cout << i << " inside " << j << '\n';
            }
        }
        if (parity) {
            ans -= r[i] * r[i];
        } else {
            ans += r[i] * r[i];
        }
    }
    cout << fixed << setprecision(9) << ans << ' ';
    cout << PI * ans << '\n';
    
    return 0;
}