#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    cout << n / 10 + (n % 10 == 9) << '\n';
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