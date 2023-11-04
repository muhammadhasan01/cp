#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long x = a * d + b * c;
    long long y = b * d;
    long long g = __gcd(x, y);
    cout << x / g << ' ' << y / g << '\n';
    
    return 0;
}