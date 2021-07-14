#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 5;

int n;
int a[N];
long long inv[N];
vector<int> divisors[N];
vector<int> primes[N];

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0;
    vector<long long> sum(N);
    for (int i = 1; i <= n; i++) {
        for (int x : divisors[a[i]]) {
            int y = a[i] / x;
            int len = primes[y].size();
            long long cur = sum[x];
            long long sub = 0;
            for (int mask = 1; mask < (1 << len); mask++) {
                int cnt_on = 0;
                int val = x;
                for (int j = 0; j < len; j++) {
                    bool bit = mask & (1 << j);
                    if (bit) {
                        cnt_on ^= 1;
                        val *= primes[y][j];
                    }
                }
                if (cnt_on % 2 == 1) {
                    sub = (sub + sum[val]) % M;
                } else {
                    sub = (sub - sum[val] + M) % M;
                }
            }
            cur = (cur - sub + M) % M;
            cur = (cur * a[i]) % M;
            cur = (cur * inv[x]) % M;
            ans = (ans + cur) % M;
        }
        for (int x : divisors[a[i]]) {
            sum[x] = (sum[x] + a[i]) % M;
        }
    }
    ans = (ans + ans) % M;
    for (int i = 1; i <= n; i++) {
        ans = (ans + a[i]) % M;
    }
    cout << (ans % M + M) % M << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("lcm.in", "r", stdin);

    for (int i = 1; i < N; i++) {
        inv[i] = modpow(i, M - 2);
    }
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    for (int i = 2; i < N; i++) {
        if (!primes[i].empty()) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            primes[j].emplace_back(i);
        }
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}