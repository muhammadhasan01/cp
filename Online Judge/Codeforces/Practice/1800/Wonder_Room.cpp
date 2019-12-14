#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
long long n, a, b, s, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    if (a * b >= 6 * n) {
        cout << a * b << '\n';
        cout << a << ' ' << b << '\n';
        return 0;
    }
    bool flag = false;
    if (a > b) {
        swap(a, b);
        flag = true;
    }
    s = INF;
    for (long long i = a; i * i <= 6 * n; i++) {
        long long tmp = 6 * n / i;
        if (tmp * i < 6 * n) tmp++;
        if (tmp < b) continue;
        if (tmp * i < s) {
            s = tmp * i;
            x = i;
            y = tmp;
        }
    }
    if (flag) swap(x, y);
    cout << s << '\n';
    cout << x << ' ' << y << '\n';

    return 0;
}
