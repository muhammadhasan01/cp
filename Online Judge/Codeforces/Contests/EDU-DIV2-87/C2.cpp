#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1);

int tc;
long double n, ans;

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
        long double halpha = 180 - alpha;
        alpha = (alpha / 180) * pi;
        long double x = 0.5 / cos(alpha);
        betha = (betha / 180) * pi;
        long double w = (2 * x);
        long double hahazz = (n - 1) * alpha / (n - 2);
        cout << fixed << setprecision(12) << w * sin(hahazz) << '\n';
    }

    return 0;
}