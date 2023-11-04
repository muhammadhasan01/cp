#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << '\n';
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