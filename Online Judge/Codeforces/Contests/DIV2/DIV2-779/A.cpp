#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int fst = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            fst = i;
            break;
        }
    }
    int ans = 0;
    for (int i = fst + 1, cur = 2; i < n; i++) {
        if (s[i] == '1') {
            cur = max(0, cur - 1);
        } else if (s[i] == '0') {
            ans += cur;
            cur = 2;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}