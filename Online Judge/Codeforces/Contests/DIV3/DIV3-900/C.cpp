#include <bits/stdc++.h>

using namespace std;

long long F(long long x) {
    return x * (x + 1) / 2;
}

void solve() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    long long small = F(k);
    long long large = F(n) - F(n - k);
    cout << (small <= x && x <= large ? "YES" : "NO") << '\n';
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