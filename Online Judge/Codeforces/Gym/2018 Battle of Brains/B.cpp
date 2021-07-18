#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

void solve() {
    long double m, d;
    cin >> m >> d;
    long double v = (3 * m) / (4 * d);
    long double area = cbrt(v * v * PI) * 4;
    cout << fixed << setprecision(4) << area << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cerr << PI << '\n';

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case " << T << ": ";
        solve();
    }

    return 0;
}