#include <bits/stdc++.h>

using namespace std;

long long m, b;

long long F(long long x) {
    return x * (x + 1) / 2;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> b;
    long long res = 0;
    for (long long i = b; i >= 0; i--) {
        long long cur = ((b - i) * m + 1) * F(i) + (i + 1) * F((b - i) * m);
        res = max(res, cur); 
    }
    cout << res << '\n';

    return 0;
}