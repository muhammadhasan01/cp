#include <bits/stdc++.h>

using namespace std;



void solve() {
    long long n;
    cin >> n;
    if (n <= 6) {
        cout << 15 << '\n';
        return;
    }
    if (n % 2 == 1) {
        n += 1;
    }
    cout << (n * 5 / 2) << '\n';
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