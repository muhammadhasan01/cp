#include <bits/stdc++.h>

using namespace std;

const int MASK = (1 << 30) - 1;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res = (res & a[i]);
    }
    if (res > 0) {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    int cur = MASK;
    for (int i = 0; i < n; i++) {
        cur = (cur & a[i]);
        if (cur == 0) {
            ++ans;
            cur = MASK;
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