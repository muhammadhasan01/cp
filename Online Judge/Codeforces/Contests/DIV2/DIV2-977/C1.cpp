#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<bool> vis(n + 1);
    for (int i = 0, j = 0; i < m; i++) {
        if (vis[b[i]]) {
            continue;
        }
        if (b[i] != a[j]) {
            cout << "TIDAK" << '\n';
            return;
        }
        vis[b[i]] = true;
        j++;
    }
    cout << "YA" << '\n';
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