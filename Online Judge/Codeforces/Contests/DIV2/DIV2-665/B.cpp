#include <bits/stdc++.h>

using namespace std;

int tc;
long long a[2][3]; // x, y, z

void solve() {
    for (int it = 0; it < 2; it++) {
        for (int i = 0; i < 3; i++)
            cin >> a[it][i];
    }
    long long ans = 0;
    long long dif;
    // 0 <-> 2
    dif = min(a[0][0], a[1][2]);
    a[1][2] -= dif, a[0][0] -= dif;
    // 2 <-> 1
    dif = min(a[0][2], a[1][1]);
    a[0][2] -= dif, a[1][1] -= dif;
    ans += 2 * dif;
    // 1 <-> 1 and 0
    dif = min(a[0][1], a[1][1] + a[1][0]);
    a[0][1] -= dif;
    // 2 <-> 2
    dif = min(a[0][2], a[1][2]);
    a[1][2] -= dif;
    // 1 <-> 2
    dif = min(a[0][1], a[1][2]);
    ans -= 2 * dif;
    cout << ans << '\n';
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