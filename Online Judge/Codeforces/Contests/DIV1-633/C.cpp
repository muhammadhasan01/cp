#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, up, dw;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        up = 1, dw = 1;
        while (up <= n) up <<= 2;
        dw = (up >> 2);
        long long ans = 0;
        if (n % 3 == 1) {
            ans = (n - dw) / 3 + dw;
        } else if (n % 3 == 2)  {
            n = n - dw + 1;
            n = n / 3;
            long long base = 0;
            while (n > 0) {
                if (n % 4 == 1) {
                    ans += (2LL << base);
                } else if (n % 4 == 2) {
                    ans += (3LL << base);
                } else if (n % 4 == 3) {
                    ans += (1LL << base);
                }
                base += 2;
                n /= 4;
            }
            ans += (dw * 2);
        } else {
            n = n - dw + 1;
            n = n / 3 - 1;
            long long base = 0;
            while (n > 0) {
                if (n % 4 == 1) {
                    ans += (3LL << base);
                } else if (n % 4 == 2) {
                    ans += (1LL << base);
                } else if (n % 4 == 3) {
                    ans += (2LL << base);
                }
                base += 2;
                n /= 4;
            }
            ans += (dw * 3);
        }
        cout << ans << '\n';
    }

    return 0;
}