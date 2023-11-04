#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    long long g = __gcd(k, 2LL);
    cout << (n % g == 0 ? "YES" : "NO") << '\n';
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