#include <bits/stdc++.h>
using namespace std;

int n, d, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> c;
    int ans = 1e9;
    for (int i = 0; i <= n / (5 * c); i++) {
        int res = (n - 5 * c * i) - ( (n - 5 * c * i) / d ) * d;
        if (res >= 0) ans = min(ans, res);
    }
    cout << ans << '\n';

    return 0;
}
