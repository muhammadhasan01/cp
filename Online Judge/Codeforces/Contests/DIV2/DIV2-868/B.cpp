#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int dif = abs(a[i] - i - 1);
        if (dif % k != 0) {
            ++cnt;
        }
    }
    if (cnt == 0) {
        cout << 0 << '\n';
        return;
    }
    if (cnt == 2) {
        cout << 1 << '\n';
        return;
    }
    cout << -1 << '\n';
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