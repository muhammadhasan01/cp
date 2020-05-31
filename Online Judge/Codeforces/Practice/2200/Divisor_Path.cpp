#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;
const long long M = 998244353;
const int INF = 1e9;

int q;
long long D;
vector<long long> prime;
long long fact[N];
long long inv[N];

long long modpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (i * fact[i - 1]) % M;
        inv[i] = modpow(fact[i], M - 2, M);
    }
    cin >> D >> q;
    for (long long i = 2; i * i <= D; i++) {
        if (D % i == 0) {
            prime.emplace_back(i);
            while (D % i == 0) D /= i;
        }
    }
    if (D > 1) prime.emplace_back(D);
    int len = prime.size();
    while (q--) {
        long long u, v;
        cin >> u >> v;
        if (u == v) {
            cout << 1 << '\n';
            continue;
        }
        vector<long long> up(len), vp(len);
        for (int i = 0; i < len; i++) {
            while (u % prime[i] == 0) {
                u /= prime[i];
                up[i]++;
            }
            while (v % prime[i] == 0) {
                v /= prime[i];
                vp[i]++;
            }
        }
        long long smaller = 0, bigger = 0;
        long long div_smaller = 1, div_bigger = 1;
        for (int i = 0; i < len; i++) {
            if (up[i] == vp[i]) continue;
            if (up[i] < vp[i]) {
                smaller += (vp[i] - up[i]);
                div_smaller = (div_smaller * inv[vp[i] - up[i]]) % M;
            } else if (up[i] > vp[i]) {
                bigger += (up[i] - vp[i])   ;
                div_bigger = (div_bigger * inv[up[i] - vp[i]]) % M;
            }
        }
        long long ans = (fact[smaller] * div_smaller) % M;
        ans = (ans * fact[bigger]) % M;
        ans = (ans * div_bigger) % M;
        cout << ans << '\n';
    }

    return 0;
}