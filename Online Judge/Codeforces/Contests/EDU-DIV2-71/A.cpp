#include <bits/stdc++.h>
using namespace std;

int tc;
int b, p, f, h, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> b >> p >> f >> h >> c;
        int ans = 0;
        for (int i = 0; i <= p; i++) {
            int nb = b - 2 * i;
            if (nb < 0) break;
            int cur = i * h + min(f, (nb / 2)) * c;
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }

    return 0;
}
