#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.length();
    long long cx = 1, cy = 1;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'R') {
            cy++;
        } else if (s[i] == 'D') {
            cx++;
        }
    }
    if (cx == 1 || cy == 1) {
        cout << n << '\n';
        return;
    }
    long long ans = 0;
    int pos = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] != s[i - 1]) {
            pos = i;
            break;
        }
    }
    ans += pos;
    long long ex = n - cx + 1, ey = n - cy + 1;
    ans += ex * ey;
    for (int i = len - 1; i >= pos; i--) {
        if (s[i] == 'R') {
            ans += ex;
        } else if (s[i] == 'D') {
            ans += ey;
        }
    }
    cout << ans << '\n';
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