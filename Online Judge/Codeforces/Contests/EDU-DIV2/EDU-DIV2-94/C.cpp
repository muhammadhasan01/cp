#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; int x;
    cin >> s >> x;
    int n = s.length();
    vector<char> w(n, '1');
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') continue;
        if (i - x >= 0) w[i - x] = '0';
        if (i + x < n) w[i + x] = '0';
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        if (i - x >= 0 && w[i - x] == '1') continue;
        if (i + x < n && w[i + x] == '1') continue;
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << w[i];
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