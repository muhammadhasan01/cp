#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    long long ans;
    if (n == 1) {
        ans = (m / 6 * 3 + max(m % 6 - 3, 0LL)) * 2;
    } else if (n == 2) {
        if (m == 2) {
            ans = 0;
        } else if (m == 3) {
            ans = 4;
        } else if (m == 7) {
            ans = 12;
        } else {
            ans = m * 2;
        }
    } else {
        ans = n * m / 2 * 2;
    }
    cout << ans << '\n';

    return 0;
}