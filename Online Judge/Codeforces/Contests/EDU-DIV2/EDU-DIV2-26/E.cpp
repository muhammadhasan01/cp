#include <bits/stdc++.h>

using namespace std;

long long get(long long x, long long y) {
    if (y == 0) return 0LL;
    long long g = __gcd(x, y);
    if (g == 1) {
        long long maks = 0;
        long long z = x;
        for (long long i = 2; i * i <= z; i++) {
            if (z % i == 0) {
                maks = max(maks, (y / i) * i);
                while (z % i == 0) {
                    z /= i;
                }
            }
        }
        if (z > 1)
            maks = max(maks, (y / z) * z);
        return (y - maks) + get(x, maks);
    } else {
        return get(x / g, y / g);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long x, y;
    cin >> x >> y;
    cout << get(x, y) << '\n';

    return 0;
}