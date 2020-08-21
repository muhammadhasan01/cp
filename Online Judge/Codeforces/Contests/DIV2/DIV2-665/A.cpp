#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, k;

void solve() {
    cin >> n >> k;
    long long ans = abs(n - k);
    if (n > k) {
        if ((n + k) % 2 == 0) ans = 0;
        else ans = min(ans, 1LL);
    }
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