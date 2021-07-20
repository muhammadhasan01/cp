#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int goals = n * (x + y);
    if (goals <= m) {
        cout << 0 << '\n';
        return;
    }
    if (y == 0) {
        cout << -1 << '\n';
        return;
    }
    cout << goals - m << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("mosalah.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}