#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES" << '\n';
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << 1 << " \n"[i == n];
        }
        return;
    }
    if (n == 1 || k == 1) {
        cout << "NO" << '\n';
        return;
    }
    if (k == 2) {
        if (n & 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    vector<int> ans;
    if (n % 2 == 1) {
        ans.emplace_back(3);
        n -= 3;
    }
    for (int rep = 0; rep < n / 2; rep++) {
        ans.emplace_back(2);
    }
    cout << "YES" << '\n';
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
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