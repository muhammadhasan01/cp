#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

int tc;
long double h, c, t;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> h >> c >> t;
        long double even = (h + c) / 2.0;
        if (t <= even) {
            cout << 2 << '\n';
            continue;
        }
        long long l = 1, r = INF, pos = 1;
        long double x = h, y = c;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long double dmid = mid;
            if (dmid * x + (dmid - 1) * y >= (2 * dmid - 1) * t) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        long double dpos = pos;
        long double odd_one = ((dpos * x) + (dpos - 1) * y) / (2 * dpos - 1);
        long double dif_odd_one = abs(t - odd_one);
        long double ppos = dpos + 1;
        long double odd_two = ((ppos * x) + (ppos - 1) * y) / (2 * ppos - 1);
        long double dif_odd_two = abs(t - odd_two);
        long double res_one = 2 * dpos - 1;
        long double res_two = 2 * ppos - 1;
        if (dif_odd_one <= dif_odd_two) {
            cout << res_one << '\n';
        } else {
            cout << res_two << '\n';
        }
    }

    return 0;
}