#include <bits/stdc++.h>

using namespace std;

int tc;
long long l, r, m;

void solve() {
    cin >> l >> r >> m;
    long long len = r - l;
    for (long long n = l; n <= r; n++) {
        long long res = m % n;
        if (res + len >= n) {
            len = n - res;
            cout << n << " " << l << " " << l + len << '\n';
            return; 
        }
        if (res - len <= 0) {
            len = res;
            cout << n << " " << l + len << " " << l << '\n';
            return;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}