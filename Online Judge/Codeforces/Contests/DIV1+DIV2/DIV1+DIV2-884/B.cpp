#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n == 2) {
        cout << 2 << " " << 1 << '\n';
        return;
    }
    int pos = (n + 1) / 2;
    vector<int> ans(n + 1);
    ans[1] = 2;
    ans[pos] = 1;
    ans[n] = 3;
    int cur = 4;
    for (int i = 1; i <= n; i++) {
        if (ans[i] > 0) {
            continue;
        }
        ans[i] = cur++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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