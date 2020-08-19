#include <bits/stdc++.h>

using namespace std;

long double h[2], t[2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int it = 0; it < 2; it++) {
        cin >> h[it] >> t[it];
    }
    long double x = (h[0] / h[1]);
    x = sqrtl(x);
    long double d = (t[1] * x - t[0]) / (x - 1);
    cout << fixed << setprecision(12) << d << '\n';

    return 0;
}