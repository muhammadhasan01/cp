#include <bits/stdc++.h>

using namespace std;

void solve() {
    int u, v;
    cin >> v >> u;
    if (v > u) {
        cout << "NO" << '\n';
        return;
    }
    for (int i = 30; i >= 0; i--) {
        int b = (u & (1 << i));
        if (b == 0) continue;
        bool ok = false;
        for (int j = i; j >= 0; j--) {
            int c = (v & (1 << j));
            if (c == 0) continue;
            v -= (1 << j);
            ok = true;
            break;
        }
        if (ok) continue;
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
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