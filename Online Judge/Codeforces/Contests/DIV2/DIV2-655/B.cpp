#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

void solve() {
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << "\n";
    } else {
        long long res;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i <= n / 2) res = max(res, i);
                long long j = n / i;
                if (j <= n / 2) res = max(res, j);
            }
        }
        cout << res << " " << n - res << "\n";
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) solve();

    return 0;
}