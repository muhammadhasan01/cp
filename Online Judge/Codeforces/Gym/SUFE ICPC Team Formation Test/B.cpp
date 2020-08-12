#include <bits/stdc++.h>

using namespace std;

int tc;
int x[2], y[2];

void solve() {
    for (int it = 0; it < 2; it++) {
        cin >> x[it] >> y[it];
    }
    if (x[0] == x[1]) {
        cout << abs(y[0] - y[1]) + 1 << '\n';
    } else if (y[0] == y[1]) {
        cout << abs(x[0] - x[1]) + 1 << '\n';
    } else {
        int dx = abs(x[0] - x[1]);
        int dy = abs(y[0] - y[1]);
        int g = __gcd(dx, dy);
        cout << g + 1 << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}