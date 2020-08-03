#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

void solve() {
    cin >> n;
    if (n % 4 == 0) {
        cout << n / 4 << '\n';
    } else if (n % 4 == 1) {
        cout << (n >= 9 ? n / 4 - 1 : -1) << '\n';
    } else if (n % 4 == 2) {
        cout << (n >= 6 ? n / 4 : -1) << '\n';
    } else {
        cout << (n >= 15 ? n / 4 - 1 : -1) << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}