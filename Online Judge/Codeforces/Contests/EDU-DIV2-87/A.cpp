#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b, c, d;

long long ceil(long long x, long long y) {
    return (x + y - 1) / y;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c >> d;
        if (a <= b) {
            cout << b << '\n';
            continue;
        }
        if (d >= c) {
            cout << -1 << '\n';
            continue;
        }
        long long dif = ceil(a - b, c - d);
        cout << b + dif * c << '\n';
    }

    return 0;
}