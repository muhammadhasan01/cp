#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> pre(n, vector<int>(2));
    vector<vector<int>> cpre(n + 1, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            pre[i][j] = cpre[a[i][j]][j];
            cpre[a[i][j]][j]++;
        }
    }
    vector<vector<int>> suf(n, vector<int>(2));
    vector<vector<int>> csuf(n + 1, vector<int>(2));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            suf[i][j] = csuf[a[i][j]][j];
            csuf[a[i][j]][j]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * (pre[i][0] + suf[i][0]) * (pre[i][1] + suf[i][1]);
    }
    long long take = 1LL * n * (n - 1) * (n - 2) / 6;
    cout << take - ans << '\n';
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