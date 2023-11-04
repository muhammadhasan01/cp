#include <bits/stdc++.h>

using namespace std;

const long long MAX = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    a[0] = 1; 
    long long cur = 1;
    for (int i = 1; i < n; i++) {
        cur = cur * 3LL;
        if (cur > MAX) {
            cout << "NO" << '\n';
            return;
        }
        a[i] = cur;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
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