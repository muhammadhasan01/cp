#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = (ret * x) % M;
        }
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    long long ans = 0;
    if (n <= k + 1) {
        for (int i = 1; i <= n; i++) {
            ans = (ans + modpow(i, k)) % M;
        }
        cout << ans << '\n';
        return 0;
    }
    long long x = 0, y = 1, z = 1;
    for (int i = 1; i <= k + 1; i++) {
        y = (y * (n - i)) % M;
        z = (z * (M - i)) % M;
    }
    z = modpow(z, M - 2);
    for (int i = 1; i <= k + 1; i++) {
        x = (x + modpow(i, k)) % M;
        y = (((y * (n - i + 1)) % M) * modpow(n - i, M - 2)) % M;
        z = (((z * (M + i - k - 2)) % M) * modpow(i, M - 2)) % M;
        ans = (ans + ((x * y) % M) * z) % M;
    }
    cout << ans << '\n';

    return 0;
}