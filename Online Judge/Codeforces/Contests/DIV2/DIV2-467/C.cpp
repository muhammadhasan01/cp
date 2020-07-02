#include<bits/stdc++.h>
using namespace std;

long double k, d, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> d >> t;
    cout << fixed << setprecision(9);
    long double period = (k + d * ceil(k / d)) / (2 * t);
    long double per1 = k / t, per2 = (d * ceil(k / d) - k)/ t;
    long double maxt = ceil(1 / period);
    long double start = period * (maxt - 1);
    long double tstart = d * ceil(k / d) * (maxt - 1);
    if (start + per1 >= 1) {
        cout << tstart + t * (1 - start) << '\n';
    } else {
        start += per1;
        tstart += k;
        cout << tstart + (2 * t) * (1 - start) << '\n';
    }

    return 0;
}
