#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1);

int tc;
long double n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        n = 2 * n;
        long double betha = (360.0) / n;
        long double alpha = (180 - betha) / 2.0;
        alpha = (alpha / 180) * pi;
        long double x = 0.5 / cos(alpha);
        betha = (betha / 180) * pi;
        long double ans = 2 * x * x * sin(betha);
        cout << fixed << setprecision(12) << ans << '\n';
    }

    return 0;
}