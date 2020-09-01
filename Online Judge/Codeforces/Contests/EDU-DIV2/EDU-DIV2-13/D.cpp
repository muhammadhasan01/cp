#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

long long a, b, n, x;

long long modpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = (ret * x) % p;
        }
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n >> x;
    if (n == 1) {
        long long res = a * x + b;
        cout << res % M << '\n';
        return 0;
    }
    if (a == 1) {
        long long res = x + ((n % M) * b);
        cout << res % M << '\n';
        return 0;
    }
    long long An = modpow(a, n, M);
    long long An_1 = ((An - 1) % M + M) % M;
    long long D = modpow(a - 1, M - 2, M);
    long long C = (An_1 * b) % M;
    C = (C * D) % M;
    long long res = (An * x) % M;
    res = (res + C) % M;
    cout << (res % M + M) % M << '\n';

    return 0;
}