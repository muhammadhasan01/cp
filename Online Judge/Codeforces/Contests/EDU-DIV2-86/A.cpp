#include <bits/stdc++.h>

using namespace std;

int tc;
long long x, y, a, b;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> x >> y >> a >> b;
        long long z = 2 * a;
        if (z <= b) {
            cout << (x + y) * a << '\n';
        } else {
            long long h = min(x, y);
            long long p = max(x, y);
            cout << h * b + (p - h) * a << '\n';
        }
    }

    return 0;
}