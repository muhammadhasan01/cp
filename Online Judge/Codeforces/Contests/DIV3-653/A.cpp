#include <bits/stdc++.h>

using namespace std;

int tc;
long long x, y, n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> x >> y >> n;
        if (x == 1) {
            cout << n << '\n';
        } else {
            cout << x * ((n - y) / x) + y << '\n';
        }
    }

    return 0;
}