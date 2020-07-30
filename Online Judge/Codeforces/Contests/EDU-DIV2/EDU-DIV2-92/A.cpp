#include <bits/stdc++.h>

using namespace std;

int tc;
long long l, r;

void solve() {
    cin >> l >> r;
    if (2 * l <= r) {
        cout << l << " " << 2 * l << '\n';
    } else {
        cout << -1 << " " << -1 << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}