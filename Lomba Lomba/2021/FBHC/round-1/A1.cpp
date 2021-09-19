#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    char cur = '#';
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        if (cc == 'F') {
            continue;
        }
        if (cur == '#') {
            cur = cc;
            continue;
        }
        if (cur == cc) {
            continue;
        }
        cur = cc;
        ans += 1;
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
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}