#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e9 + 7;

int n, m, g;
int fac[N], inv[N];

int modpow(long long x, int y) {
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

int C(int a, int b) {
    if (b > a) return 0;
    long long ret = ((1LL) * fac[a] * inv[b]) % M;
    ret = ((1LL) * ret * inv[a - b]) % M;
    return ret;
}

int get(int x, int y, bool one) {
    int ret;
    if (one) {
        ret = C(x + y, y) - get(x, y, false);
    } else {
        if (x == 0) {
            ret = (y > 1);
        } else if (y == 0) {
            ret = (x & 1);
        } else {
            ret = C(x + y - 1, y - 1) + get(x - 1, y, true);
        }
    }
    ret = (ret % M + M) % M;
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> g;
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        long long res = ((1LL) * i * fac[i - 1]) % M;
        fac[i] = res;
        inv[i] = modpow(fac[i], M - 2);
    }
    cout << get(n, m, g) << '\n';

    return 0;
}