#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int x = 0; x <= n; x++) {
        int liars = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                liars++;
            }
        }
        if (liars == x) {
            cout << x << '\n';
            return;
        }
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