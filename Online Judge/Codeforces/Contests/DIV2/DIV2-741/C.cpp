#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<char> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mid = n / 2 + 1;
    for (int i = mid; i <= n; i++) {
        if (a[i] == '0') {
            cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << '\n';
            return;
        }
    }
    int dim = mid - (n % 2 == 0);
    for (int i = dim; i >= 1; i--) {
        if (a[i] == '0') {
            cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
            return; 
        }
    }
    cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}