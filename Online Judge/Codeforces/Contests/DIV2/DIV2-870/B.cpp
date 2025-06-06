#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;   
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int g = 0;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        int dif = abs(a[i] - a[j]);
        g = __gcd(g, dif);
    }
    cout << g << '\n';
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