#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        b[i] = cc - '0';
    }
    vector<int> a(n);
    a[0] = 1;
    vector<int> res(n);
    res[0] = a[0] + b[0];
    for (int i = 1; i < n; i++) {
        if (b[i] + 1 == res[i - 1]) {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
        res[i] = a[i] + b[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << '\n';
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