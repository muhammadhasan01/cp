#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[a[i]] = b[i];
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << pos[i + 1] << " \n"[i == n - 1];
    }
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