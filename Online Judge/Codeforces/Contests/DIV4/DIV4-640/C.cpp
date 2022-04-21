#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

int tc;
long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        long long l = 0, r = INF, ans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (mid - mid / n >= k) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        if (ans % n == 0) ans--;
        cout << ans << '\n';
    }

    return 0;
}