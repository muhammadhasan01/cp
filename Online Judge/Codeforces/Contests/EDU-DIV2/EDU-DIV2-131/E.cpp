#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> lcp(n + 1, vector<int>(m + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            lcp[i][j] = a[i] == b[j] ? lcp[i + 1][j + 1] + 1 : 0;
        }
    }
    bool flag = false;
    int ans = INF;
    for (int i = 0, j = 0; i < n; i++) {
        if (j < m && a[i] == b[j]) {
            j++;
        }
        if (j == m) {
            flag = true;
        }
        for (int t = 0; t <= j; t++) {
            ans = min(ans, n - lcp[i + 1][t] + i + 1 - t + 1);
        }
    }
    if (flag) {
        ans = min(ans, n - lcp[0][0]);
        cout << ans << "\n";
    } else {
        cout << -1 << '\n';
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