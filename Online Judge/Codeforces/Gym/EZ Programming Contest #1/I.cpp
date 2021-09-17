#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;
    long long res = 0;
    for (int i = 61; i >= 0; i--) {
        bool a = x & (1LL << i);
        bool b = y & (1LL << i);
        if (a == 0 && b == 1) {
            cout << -1 << '\n';
            return;
        }
        if (a == 1 && b == 0) {
            res += 1LL << i;
        }
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}