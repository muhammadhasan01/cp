#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 2) {
            ++cnt;
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) {
            ++cur;
        }
        if (cnt - cur == cur) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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