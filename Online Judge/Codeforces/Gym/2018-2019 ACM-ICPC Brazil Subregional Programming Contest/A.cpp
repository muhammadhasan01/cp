// Failed :(
#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 1e5 + 5;

long long n, m, L, R;

long long F(long long x) {
    long long ret = x * (x + 1) / 2;
    return ret % M;
}

long long G(long long x) {
    long long ret = F(m) - F(m - x);
    return (ret % M + M) % M;
}

long long get(long long x) {
    if (x == 0) return 0;
    long long qx = x * x;
    long long ret = (n - 1) * m + (m - 1) * n;
    ret %= M;
    vector<long long> dp(n + 1);
    for (long long i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        long long dx = (i - 1) * (i - 1);
        long long l = 2, r = m, at = 0; 
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if ((mid - 1) * (mid - 1) + dx <= qx) {
                at = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (at == 0) continue;
        long long cur = G(at);
        cur = (cur - m);
        cur = (cur % M + M) % M;
        cur = (2LL * cur) % M;
        dp[i] = (dp[i] + cur) % M;
    }
    for (int i = 1; i <= n; i++) {
        ret = (ret + dp[i]) % M;
    }
    for (long long i = 2; i < n; i++) {
        for (long long j = i; j < m; j += i) {
            if (i * i + j * j > qx) break;
            ret = (ret - 2LL * (n - i) * (m - j));
            ret = (ret % M + M) % M;
        }
    }
    for (long long j = 2; j < m; j++) {
        for (long long i = j + j; i < n; i += j) {
            if (i * i + j * j > qx) break;
            ret = (ret - 2LL * (n - i) * (m - j));
            ret = (ret % M + M) % M;
        }
    }
    return ret;
}

long long getExact(long long x) {
    if (x == 1) {
        long long res = (m - 1) * n + (n - 1) * m;
        res = (res % M + M) % M;
        return res;
    }
    vector<long long> dp(n + 1);
    long long qx = x * x;
    for (long long i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        long long dx = (i - 1) * (i - 1);
        long long l = 1, r = m, at = -1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if ((mid - 1) * (mid - 1) + dx <= qx) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at == -1) continue;
        if ((at - 1) * (at - 1) + dx != qx) continue;
        if (__gcd(at - 1, i - 1) > 1) continue;
        dp[i] = (dp[i] + 2LL * (m - at + 1)) % M;
    }
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = (ret + dp[i]) % M;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> L >> R;
    if (n < m) swap(n, m);
    long long ans = get(R) - get(L) + getExact(L);
    ans = (ans % M + M) % M;
    cout << ans << '\n';

    return 0;
}