#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    int cur = 1;
    for (int i = 0; i < n; i += 2) {
        int j = (i + 1) % n;
        a[1][i] = cur + 1;
        a[0][j] = cur;
        cur += 2;
    }
    for (int i = 1; i < n; i += 2) {
        int j = (i + 1) % n;
        a[1][i] = cur + 1;
        a[0][j] = cur;
        cur += 2;
    }
    for (int i = 0; i < 2; i++) {
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