#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

void solve() {
    cin >> n;
    cout << n / 2 + 1 << '\n';
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