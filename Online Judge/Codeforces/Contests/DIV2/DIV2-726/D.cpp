#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << (n % 2 == 1 || ((n & (n - 1)) == 0 && __builtin_ctz(n) % 2 == 1) ? "Bob" : "Alice") << '\n';
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