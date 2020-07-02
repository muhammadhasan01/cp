#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        long long ans = 2e9;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i <= k) ans = min(ans, n / i);
                if (n / i <= k) ans = min(ans, i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}