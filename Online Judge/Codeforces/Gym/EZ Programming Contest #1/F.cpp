#include <bits/stdc++.h>

using namespace std;

const int K = 1e5;

void solve() {
    long long n;
    cin >> n;
    for (int it = 0; it < K; it++) {
        long long l = 1, r = n, at = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (mid * (mid + 1) <= 2 * n) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        for (int i = 0; i < at; i++) {
            cout << char(it % 26 + int('a'));
        }
        n -= at * (at + 1) / 2;
        if (n == 0) {
            break;
        }
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}