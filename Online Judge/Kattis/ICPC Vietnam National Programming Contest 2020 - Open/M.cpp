#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d;

void solve() {
    cin >> a >> b >> c >> d;
    long long dx = abs(a - c);
    long long dy = abs(b - d);
    if (dx > dy) swap(dx, dy);
    long long ans = dx + dx;
    dy -= dx;
    if (dy & 1) {
        ans += (dy - 1) * 2 + 1;
    } else {
        ans += dy * 2;
    }
    cout << ans << '\n';
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