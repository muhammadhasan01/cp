#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pre(n + 2);
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        if (cc == '+') {
            a[i] = 1;
        } else if (cc == '-') {
            a[i] = -1;
        }
        if (i % 2 == 0) {
            a[i] = -a[i];
        }
        pre[i] = pre[i - 1] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int sz = r - l + 1;
        if (sz % 2 == 1) {
            cout << 1 << '\n';
        } else {
            cout << (pre[r] - pre[l - 1] == 0 ? 0 : 2) << '\n';
        }
    }
}   

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}