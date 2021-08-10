#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    auto get_char = [&](int x) -> char {
        return char(int('a') + x);
    };
    if (n <= 26) {
        for (int i = 0; i < n; i++) {
            cout << get_char(i);
        }
        cout << '\n';
        return;
    }
    if (n % 2 == 1) {
        cout << get_char(25);
        n--;
    }
    int m = n / 2;
    for (int i = 0; i < m - 1; i++) {
        cout << get_char(0);
    }
    cout << get_char(1);
    for (int i = 0; i < m; i++) {
        cout << get_char(0);
    }
    cout << '\n';
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