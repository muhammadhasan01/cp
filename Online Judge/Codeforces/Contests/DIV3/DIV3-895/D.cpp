#include <bits/stdc++.h>

using namespace std;

long long F(long long x) {
    return x * (x + 1) / 2;
}

void solve() {
    long long n, x, y;
    cin >> n >> x >> y;
    long long lcm = x * (y / __gcd(x, y));
    long long both = n / lcm;
    long long X = n / x - both;
    long long Y = n / y - both;
    long long sumX = F(n) - F(n - X);
    long long sumY = F(Y);
    cout << sumX - sumY << '\n';
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