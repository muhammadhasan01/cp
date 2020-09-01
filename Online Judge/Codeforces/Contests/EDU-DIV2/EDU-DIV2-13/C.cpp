#include <bits/stdc++.h>

using namespace std;

long long n, a, b, p, q;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> p >> q;
    long long c = (a / __gcd(a, b)) * b;
    long long x = n / c;
    long long y = n / a - x;
    long long z = n / b - x;
    cout << y * p + z * q + x * max(p, q) << '\n';

    return 0;
}