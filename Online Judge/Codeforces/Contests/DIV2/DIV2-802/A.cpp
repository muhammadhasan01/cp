#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;
    cout << m * (m - 1) / 2 + m * ((n * (n + 1)) / 2) << '\n';
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