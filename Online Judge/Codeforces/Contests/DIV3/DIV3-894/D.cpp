#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e9;

void solve() {
    long long n;
    cin >> n;
    long long l = 0, r = INF, at = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1LL;
        if (mid * (mid - 1) / 2 <= n) {
            at = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << at + n - (at * (at - 1) / 2LL) << '\n';
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