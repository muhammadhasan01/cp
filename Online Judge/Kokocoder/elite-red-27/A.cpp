#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long x;
    cin >> x;
    long long a = 1, b = x;
    for (long long i = 1; i * i <= x; i++) {
        if (x % i != 0) {
            continue;
        }
        long long p = i, q = x / i;
        if (p * (q / __gcd(p, q)) == x && max(p, q) < max(a, b)) {
            a = p;
            b = q;
        }
    }
    cout << a << ' ' << b << '\n';
    
    return 0;
}