#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        if (cc == '1') {
            pos.emplace_back(i);
        }
    }
    int len = (int) pos.size();
    if (len == 0) {
        cout << 0 << '\n';
        return;
    }
    if (len == 1) {
        int ans = 11;
        if (pos[0] - 1 <= k) {
            ans = min(ans, 10);
        }
        if (n - pos[0] <= k) {
            ans = min(ans, 1);
        }
        cout << ans << '\n';
        return;
    }
    int ans = len * 11;
    for (int l : {0, 1}) {
        for (int r : {0, 1}) {
            int need = 0;
            int cur = len * 11;
            if (l == 1) {
                need += pos[0] - 1;
                cur -= 1;
            }
            if (r == 1) {
                need += n - pos[len - 1];
                cur -= 10;
            }
            if (need <= k) {
                ans = min(ans, cur);
            }
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