#include <bits/stdc++.h>

using namespace std;


long long n;
long long fast(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) res *= x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long m = n;
    long long last;
    int cnt = 0, cur = 0;
    while (m > 0) {
        last = m;
        m /= 10;
        cnt++;
    }
    cout << fast(10, cnt - 1) * (last + 1) - n << '\n';

    return 0;
}
