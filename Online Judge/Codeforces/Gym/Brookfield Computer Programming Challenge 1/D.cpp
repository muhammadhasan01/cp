#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << "Neither" << '\n';
        return;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << "Composite" << '\n';
            return;
        }
    }
    cout << "Prime" << '\n';
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