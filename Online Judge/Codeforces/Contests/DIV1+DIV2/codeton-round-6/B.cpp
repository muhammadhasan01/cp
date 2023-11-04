#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int B = 0;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        B = (B | b);
    }
    int X = 0, Y = 0;
    for (int i = 0; i < n; i++) {
        X = (X ^ a[i]);
        a[i] = (a[i] | B);
        Y = (Y ^ a[i]);
    }
    if (X > Y) {
        swap(X, Y);
    }
    cout << X << ' ' << Y << '\n';
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