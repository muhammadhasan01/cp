#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    auto ask = [&](int i) -> int {
        cout << "? " << i << endl;
        int res;
        cin >> res;
        return res;
    };

    int ans = ask(1);
    int rem = n % k;
    if (rem > 0) {
        ans ^= ask(1 + rem / 2);
        ans ^= ask(1 + rem);
    }
    for (int i = k + rem + 1; i <= n; i += k) {
        ans ^= ask(i);
    }
    cout << "! " << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}