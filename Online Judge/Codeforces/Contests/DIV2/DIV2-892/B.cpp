#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    if (n == 1) {
        cout << a[0][0] << '\n';
        return;
    }
    vector<int> vals(n);
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        vals[i] = a[i][1];
        mini = min(mini, a[i][0]);
    }
    sort(vals.begin(), vals.end());
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += vals[i];
    }
    ans += mini;
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