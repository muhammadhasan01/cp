#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << s[0] << s[0] << '\n';
        return;
    }
    if (s[0] == s[1]) {
        cout << s[0] << s[0] << '\n';
        return;
    }
    string ans = "";
    ans += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1]) {
            break;
        }
        if (s[i] <= s[i - 1]) {
            ans += s[i];
            continue;
        }
    }
    string rev = ans;
    reverse(rev.begin(), rev.end());
    cout << ans << rev << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}