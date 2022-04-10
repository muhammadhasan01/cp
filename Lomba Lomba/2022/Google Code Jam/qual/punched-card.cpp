#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    n += 1, m += 1;
    for (int i = 0; i < n; i++) {
        string res(2 * m, '#');
        for (int j = 0; j < m; j++) {
            res[2 * j] = '+';
            res[2 * j + 1] = '-';
        }
        if (i == 0) {
            res[0] = res[1] = '.';
        }
        for (int j = 0; j < 2 * m - 1; j++) {
            cout << res[j];
        }
        cout << '\n';
        if (i == n - 1) {
            break;
        }
        for (int j = 0; j < 2 * m - 1; j++) {
            if (res[j] == '+') {
                res[j] = '|';
            } else if (res[j] == '-') {
                res[j] = '.';
            }
            cout << res[j];
        }
        cout << '\n';
    }
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}