#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int XOR = 0;
    int ALL = 0;
    for (int i = 1; i <= n; i++) {
        int num = s[i - 1] - '0';
        if (num == 0) {
            XOR ^= a[i];
        }
        ALL ^= a[i];
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = (a[i] ^ pre[i - 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            int val = (pre[r] ^ pre[l - 1]);
            XOR ^= val;
        } else if (tp == 2) {
            int g;
            cin >> g;
            int ans = XOR;
            if (g == 1) {
                ans ^= ALL;
            }
            cout << ans << ' ';
        }
    }
    cout << '\n';
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