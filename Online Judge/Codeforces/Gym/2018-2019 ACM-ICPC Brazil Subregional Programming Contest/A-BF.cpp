#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 1e5 + 5;;

vector<int> prime[N];

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
    long long ret = 0;
    for (long long i = 1; i <= n; i++) {
        // repeat the last process
        ret = (2LL * ret) % M;
        // then we only have to find pair between first row and current row
        if (i == 1) {
            // (1, 2), (2, 3), ..., (m - 1, m)
            ret = m - 1;
            continue;
        }
        long long dx = (i - 1) * (i - 1);
        long long l = 1, r = m, at = 1; 
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if ((mid - 1) * (mid - 1) + dx <= qx) {
                at = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // at => maximal position where (i, 1) can go to (1, at)
        long long cur = G(at);
        if (i == 2) {
            cur = ((2LL * cur - m) % M + M) % M;
            ret = (ret + cur) % M;
            continue;
        }
        cur = (cur - m);
        cur = (cur % M + M) % M;
        for (long long j = 2; j < at; j++) {
            if (__gcd(i - 1, j) == 1) continue;
            cur = (cur - (m - j));
            cur = (cur % M + M) % M;
        }
        cur = (2LL * cur) % M;
        ret = (ret + cur) % M;
    }
    return ret;
}

long long getExact(long long x) {
    if (x == 1) {
        long long res = (m - 1) * n + (n - 1) * m;
        res = (res % M + M) % M;
        return res;
    }
    long long ret = 0;
    long long qx = x * x;
    for (long long i = 2; i <= n; i++) {
        ret = (2 * ret) % M;
        long long l = 1, r = m, at = -1;
        long long dx = (i - 1) * (i - 1);
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
        ret = (ret + 2LL * (m - at + 1)) % M; 
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 2; i < N; i++) {
        if (!prime[i].empty()) continue;
        for (int j = i; j < N; j += i) {
            prime[j].emplace_back(i);
        }
    }
    cin >> n >> m >> L >> R;
    if (n > m) swap(n, m);
    long long ans = get(R) - get(L) + getExact(L);
    ans = (ans % M + M) % M;
    cout << ans << '\n';

    return 0;
}