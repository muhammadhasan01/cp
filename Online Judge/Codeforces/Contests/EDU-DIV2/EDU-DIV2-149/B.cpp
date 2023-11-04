#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char cur = s[0];
    int cnt = 1;
    int mx = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == cur) {
            cnt++;
            mx = max(mx, cnt);
        } else {
            cnt = 1;
            mx = max(mx, cnt);
        }
        cur = s[i];
    }
    mx = max(mx, cnt);
    cout << mx + 1 << '\n';
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