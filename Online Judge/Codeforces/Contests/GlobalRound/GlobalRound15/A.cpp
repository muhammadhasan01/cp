#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    string s = str;
    sort(str.begin(), str.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != str[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
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