#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = n - 2; i >= 0; i--) {
        int res = (s[i] - '0') + (s[i + 1] - '0');
        if (res >= 10) {
            cout << s.substr(0, i) << res << s.substr(i + 2) << '\n';
            return;
        }
    }
    int res = (s[0] - '0') + (s[1] - '0');
    cout << res << s.substr(2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        solve();
    }

    return 0;
}