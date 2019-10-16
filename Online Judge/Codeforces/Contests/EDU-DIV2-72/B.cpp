#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;


const int N = 105;
int tc, n;
ll x;
pll p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        long long dif = -1;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second;
            dif = max(dif, p[i].first - p[i].second);
        }
        sort(p + 1, p + 1 + n);
        if (dif <= 0 && p[n].first < x) {
            cout << -1 << '\n';
            continue;
        }
        int ans = 0;
        while (x > 0) {
            if (p[n].first >= x) {
                ans++;
                x = 0;
            } else {
                long long l = 1, r = (x + dif - 1) / dif, pos = 0;
                while (l <= r) {
                    long long mid = (l + r) >> 1;
                    if (x - mid * dif <= p[n].first) {
                        r = mid - 1;
                        pos = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                x -= dif * pos;
                ans += pos;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
