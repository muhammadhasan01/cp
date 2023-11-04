#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int cur = 0;
    for (int j = 0; j < n; j += 2) {
        for (int i = 0; i < n - j; i++) {
            a[i][i + j] = ++cur;
        }
        if (j > 0) {
            for (int i = 0; i < n - j; i++) {
                a[i + j][i] = ++cur;
            }
        }
    }
    cur = n * n + 1;
    for (int j = 1; j < n; j += 2) {
        for (int i = 0; i < n - j; i++) {
            a[i][i + j] = --cur;
        }
        for (int i = 0; i < n - j; i++) {
            a[i + j][i] = --cur;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
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