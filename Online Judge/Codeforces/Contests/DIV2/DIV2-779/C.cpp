#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "NO" << '\n';
        return;
    }
    for (int i = 0; i + 1 < n; i++) {
        int l = (i + pos) % n;
        int r = (i + pos + 1) % n;
        if (c[r] > c[l]) {
            if (c[r] - c[l] > 1) {
                cout << "NO" << '\n';
                return;
            }
        }
        if (c[r] == 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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