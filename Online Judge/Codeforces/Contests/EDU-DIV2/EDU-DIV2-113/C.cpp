#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;
const int N = 2e5 + 5; 

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n - 1] - a[n - 2] >= 2) {
        cout << 0 << '\n';
        return;
    }
    if (a[n - 1] == a[n - 2]) {
        cout << fact[n] << '\n';
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < a[n - 2]) {
            cnt++;
        }
    }
    long long ans = fact[n];
    long long res = 0;
    for (int i = 0; i <= cnt; i++) {
        long long cur = (C(cnt, cnt - i) * fact[n - i - 1]) % M;
        cur = (cur * fact[i]) % M;
        res = (res + cur) % M;
    }
    ans = (ans - res) % M;
    cout << (ans % M + M) % M << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}