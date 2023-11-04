#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> ok(n);
    for (int i = 0, j = 1; i < n; i++) {
        if (a[i] == j) {
            ok[i] = true;
            ++j;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!ok[i]) {
            ++cnt;
        }
    }
    cout << (cnt + k - 1) / k << '\n';
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