#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int height = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            height += a[i];
            continue;
        }
        if (a[i] == 0) {
            if (a[i - 1] == 0) {
                cout << -1 << '\n';
                return;
            }
            continue;
        }
        if (a[i] == 1) {
            if (a[i - 1] == 0) {
                height += 1;
            } else {
                height += 5;
            }
        }
    }
    cout << height << '\n';
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