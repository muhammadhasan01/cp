#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    long long maksi = 0LL;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        maksi = max(maksi, x);
    }
    if (maksi == 1) {
        cout << maksi * k << '\n';
    } else {
        cout << maksi * k - 1 << '\n';
    }
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