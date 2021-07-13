#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;
const int N = 3e5 + 5; 

int n;
char s[N];
long long fact[N];
long long invf[N];

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

long long inv(long long x) {
    return modpow(x, M - 2);
}

long long C(int a, int b) {
    if (a < b) return 0;
    long long ret = (fact[a] * invf[b]) % M;
    ret = (ret * invf[a - b]) % M;
    return ret;
}

void init() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        invf[i] = inv(fact[i]);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int x = 0, y = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            x++;
            y += cnt / 2;
            cnt = 0;
            continue;
        }
        ++cnt;
    }
    y += cnt / 2;
    cout << C(x + y, x) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}