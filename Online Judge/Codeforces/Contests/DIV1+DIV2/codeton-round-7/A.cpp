#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int x = n; x >= 1; x--) {
        if (is_sorted(a.begin(), a.end())) {
            cout << "YES" << '\n';
            return;
        }
        int pos = -1;
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] == x) {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            for (int i = pos; i + 1 < x; i++) {
                swap(a[i], a[i + 1]);
            }
        }
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n'; 
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