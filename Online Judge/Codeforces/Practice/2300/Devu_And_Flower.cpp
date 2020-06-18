#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long long M = 1e9 + 7;

int n;
long long s;
long long F[N], inv[N];

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
    if (b > a) return 0LL;
    if (a - b < b) b = a - b;
    a %= M;
    long long ret = 1;
    for (int i = 0; i < b; i++) {
        ret = (ret * (a - i)) % M;
        ret = (ret * inv[i + 1]) % M;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        inv[i] = modpow(i, M - 2, M);
    }
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> F[i];
    }
    long long ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long res = s;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                res -= (F[i] + 1);
                tot++;
            }
        }
        if (res < 0) continue;
        long long temp = C(res + n - 1, n - 1);
        if (tot & 1) temp = -temp;
        ans += temp;
        ans = ((ans % M) + M) % M;
    }
    cout << ans << '\n';

    return 0;
}