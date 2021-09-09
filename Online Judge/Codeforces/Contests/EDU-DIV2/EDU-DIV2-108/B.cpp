#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;
    long long res = (m - 1) + m * (n - 1);
    cout << (res == k ? "YES" : "NO") << '\n';
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