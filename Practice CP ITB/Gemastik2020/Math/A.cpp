#include <bits/stdc++.h>

using namespace std;

int tc;
int a, b;

void solve() {
    cin >> a >> b;
    int res = b - a % b;
    if (res == b) res = 0;
    cout << res << '\n';
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