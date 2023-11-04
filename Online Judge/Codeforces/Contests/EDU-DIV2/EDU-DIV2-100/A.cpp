#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sum = a + b + c;
    if (sum % 9 != 0) {
        cout << "NO" << '\n';
        return;
    }
    long long need = sum / 9;
    if (min({a, b, c}) < need) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
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