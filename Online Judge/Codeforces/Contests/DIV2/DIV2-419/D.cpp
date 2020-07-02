#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long M = 1e9 + 7;

long long n;
long long a[N];
long long fac[N], inv[N];

long long modpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
}

long long C(long long a, long long b) {
    if (a < b) return 0LL;
    long long ret = (fac[a] * inv[b]) % M;
    ret = (ret * inv[a - b]) % M;
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fac[0] = inv[0] = 1LL;
    for (int i = 1; i < N; i++) {
        fac[i] = (i * fac[i - 1]) % M;
        inv[i] = modpow(fac[i], M - 2, M);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long rem = n % 4;
    long long ans = 0;
    if (rem == 0) {
        for (int i = 0; i < n; i++) {
            if (!(i & 1)) {
                ans = (ans + C((n - 2) / 2, i / 2) * a[i]);
            } else {
                ans = (ans - C((n - 2) / 2, i / 2) * a[i]);
            }
            ans = (ans % M + M) % M;
        }
    } else if (rem == 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans = (ans + C((n - 1) / 2, i / 2) * a[i]);
            }
            ans = (ans % M + M) % M;
        }
    } else if (rem == 2) {
        for (int i = 0; i < n; i++) {
            ans = (ans + C((n - 2) / 2, i / 2) * a[i]);
            ans = (ans % M + M) % M;
        }
    } else if (rem == 3) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans = (ans + C((n - 3) / 2, i / 2) * a[i] - C((n - 3) / 2, i / 2 - 1) * a[i]);
            } else {
                ans = (ans + 2LL * C((n - 3) / 2, i / 2) * a[i]);
            }
            ans = (ans % M + M) % M;
        }
    }
    cout << (ans % M + M) % M << "\n";

    return 0;
}