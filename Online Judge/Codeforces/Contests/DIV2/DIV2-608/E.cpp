#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
long long n, k;

bool can(long long x) {
    long long ret = 0;
    long long l = x, r = x + 1 - (x % 2);
    while (r <= n) {
        ret += (r - l + 1);
        l = (l * 2);
        r = (r * 2 + 1);
    }
    ret += max(0LL, n - l + 1);
    return (ret >= k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if (n == k) {
        cout << 1 << '\n';
        return 0;
    }
    long long l = 1, r = INF;
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(2 * mid + 1)) {
            l = mid + 1;
            ans = max(ans, 2 * mid + 1);
        } else {
            r = mid - 1;
        }
    }
    l = 1, r = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(2 * mid)) {
            l = mid + 1;
            ans = max(ans, 2 * mid);
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
