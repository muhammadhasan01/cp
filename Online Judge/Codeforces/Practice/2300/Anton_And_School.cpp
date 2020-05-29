#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long M = 1e9 + 7;

char s[N];
int n;
int pre[N], suf[N];
long long fac[N], inv[N];
long long ans;

long long fast(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

long long C(long long a, long long b) {
    if (a < b) return 0LL;
    if (a == b) return 1LL;
    long long ret = (fac[a] * inv[b]) % M;
    ret = (ret * inv[a - b]) % M;
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = (i * fac[i - 1]) % M;
        inv[i] = fast(fac[i], M - 2, M);
    }
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '(');
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + (s[i] == ')');
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == ')') continue;
        ans = (ans + C(pre[i] + suf[i] - 1, pre[i])) % M;
    }
    cout << ans << '\n';

    return 0;
}