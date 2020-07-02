#include <bits/stdc++.h>

using namespace std;

const long long M = 998244353;
const int N = 5e5 + 5;

long long n, k;
long long prec[N];
long long inv[N];

long long fast(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
}

long long C(long long a, long long b) {
    if (b > a) return 0;
    if (a == b) return 1;
    long long ret = prec[a];
    ret = (ret * inv[b]) % M;
    ret = (ret * inv[a - b]) % M;
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    prec[0] = inv[0] = 1;
    for (long long i = 1; i < N; i++) {
        prec[i] = (i * prec[i - 1]) % M;
        inv[i] = fast(prec[i], M - 2, M);
    }
    cin >> n >> k;
    if (k > n) {
        cout << 0 << '\n';
        return 0;
    } else if (n == k) {
        cout << 1 << '\n';
        return 0;
    } else if (k == 1) {
        cout << n << '\n';
        return 0;
    }
    long long ans = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        long long sz = n / i - 1;
        if (sz < k - 1) continue;
        ans = (ans + C(sz, k - 1)) % M;
        cerr << ans << '\n';
    }
    cout << ans << '\n';

    return 0;
}