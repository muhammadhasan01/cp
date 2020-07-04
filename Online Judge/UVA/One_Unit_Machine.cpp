#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int MAX = 1e6 + 5;
const long long M = 1e9 + 7;

int tc;
int n, k[N];
long long pre[N];
long long fac[MAX], inv[MAX];

long long modpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ret = (ret * x) % M;
        }
        y /= 2;
        x = (x * x) % M;
    }
    return ret;
}

long long C(long long a, long long b) {
    if (a < b) return 0;
    long long ret = (fac[a] * inv[b]) % M;
    ret = (ret * inv[a - b]) % M;
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fac[0] = inv[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fac[i] = (i * fac[i - 1]) % M;
        inv[i] = modpow(fac[i], M - 2, M);
    }
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> k[i];
            pre[i] = k[i] + pre[i - 1];
        }
        long long res = 1;
        for (int i = n; i >= 1; i--) {
            res = (res * C(pre[i] - 1, k[i] - 1)) % M;
        }
        cout << "Case " << tt << ": ";
        cout << res << '\n';
    }

    return 0;
}