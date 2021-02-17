#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 1e9;
    for (int x = b; x <= b + 50; x++) {
        if (x == 1) continue;
        int res = x - b;
        int y = a;
        while (y > 0) {
            res++;
            y /= x;
        }
        ans = min(ans, res);
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