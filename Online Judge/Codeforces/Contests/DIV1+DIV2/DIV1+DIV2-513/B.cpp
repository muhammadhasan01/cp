#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n <= 18) {
        cout << n << '\n';
    } else {
        string m = to_string(n);
        long long k = 0;
        int cnt = 0;
        while (10 * k + 9 <= n) {
            k = (10 * k + 9);
            cnt++;
        }
        long long d = (m[0] - '0'), t = -1;
        if (d > 1) {
            t = pow(10, cnt) * (d - 1) + k;
            if (t < n) k = t;
        }
        d = n - k;
        int ans = 0;
        while (k > 0) {
            ans += k % 10;
            k /= 10;
        }
        while (d > 0) {
            ans += d % 10;
            d /= 10;
        }
        cout << ans << '\n';
    }

    return 0;
}
