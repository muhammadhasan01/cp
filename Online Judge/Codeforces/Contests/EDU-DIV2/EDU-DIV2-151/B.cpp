#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long xa, ya;
    long long xb, yb;
    long long xc, yc;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    xb -= xa, yb -= ya;
    xc -= xa, yc -= ya;
    long long ans = 1;
    if (xb * xc > 0) {
        ans += min(abs(xb), abs(xc));
    }
    if (yb * yc > 0) {
        ans += min(abs(yb), abs(yc));
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