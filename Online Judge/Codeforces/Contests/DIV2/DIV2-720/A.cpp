#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long A, B;
    cin >> A >> B;
    if (B == 1) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    cout << A << ' ' << A * (2 * B - 1) << ' ' << A * B * 2 << '\n';
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