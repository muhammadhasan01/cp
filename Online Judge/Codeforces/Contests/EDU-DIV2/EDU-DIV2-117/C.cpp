#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;

    long long R = 2LL * k - 1;

    auto F = [&](long long n) -> long long {
        return n * (n + 1) / 2;
    };

    auto getVal = [&](long long len) {
        if (len <= k) {
            return F(len);
        }
        return F(k) + (F(k - 1) - F(R - len));
    };

    long long l = 1, r = R, ans = R;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (getVal(mid) >= x) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}