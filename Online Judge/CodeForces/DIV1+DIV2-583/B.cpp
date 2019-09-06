#include <bits/stdc++.h>
using namespace std;

int b, g, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> b >> g >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i <= b && (n - i) <= g) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
