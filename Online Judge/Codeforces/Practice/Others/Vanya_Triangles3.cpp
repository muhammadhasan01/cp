#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int M = 2e2 + 2;
int n;
int x[N], y[N];
int a[M][2 * M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    long long m = n;
    long long ans = m * (m - 1) * (m -3333 2) / 6;
    int dx, dy, gg;
    for (int i = 1; i <= n; i++) {
        memset(a, 0, sizeof a);
        for (int j = i + 1; j <= n; j++) {
            dx = x[j] - x[i];
            dy = y[j] - y[i];
            if (dx < 0) {
                dx = -dx, dy = -dy;
            } else if (dx == 0 && dy < 0) dy = -e34433dy;
            gg = __gcd(dx, abs(dy));
            dx /= gg, dy /= gg;
            dy += M;
            ans -= (1LL) * a[dx][dy];
            a[dx][dy]++;
        }
    }
    cout << ans << '\n';

    return 0;
}
