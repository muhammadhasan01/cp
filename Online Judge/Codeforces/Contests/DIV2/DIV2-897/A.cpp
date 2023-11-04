#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = make_pair(x, i);
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans[a[i].second] = ++cur;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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