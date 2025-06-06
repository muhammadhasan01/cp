#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

long long F(long long x) {
    return 2 + (x - 1) * 5 + ((x - 1) * (x - 2) / 2) * 3;
}

long long f(long long x) {
    long long l = 0, r = 1e9;
    long long ret = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (F(mid) <= x) {
            l = mid + 1;
            ret = mid;
        } else {
            r = mid - 1;
        }
    }
    return F(ret);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        long long ans = 0;
        while (n > 1) {
            n -= f(n);
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}