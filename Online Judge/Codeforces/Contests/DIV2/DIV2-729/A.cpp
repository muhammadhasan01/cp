#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if (x & 1) odd++;
        else even++;
    }
    cout << (even == odd ? "Yes" : "No") << '\n';
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