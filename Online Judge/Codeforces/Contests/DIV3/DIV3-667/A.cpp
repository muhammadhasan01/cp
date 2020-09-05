#include <bits/stdc++.h>

using namespace std;

int tc;


void solve() {
    int a, b;
    cin >> a >> b;
    cout << (abs(a - b) + 9) / 10 << '\n';
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