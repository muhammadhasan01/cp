#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int q;
long long n, x, a, y, b, c, k1, k2, k3;
long long k, p[N];

bool can(int m) {
    long long res = 0;
    k1 = m / a, k2 = m / b, k3 = m / c;
    int i;
    for (i = 1; i <= m; i++) {
        if (k3 > 0) {
            k1--, k2--, k3--;
            res += (p[i] * (x + y));
        } else if (k1 > 0) {
            res += (p[i] * x);
            k1--;
        } else if (k2 > 0) {
            res += (p[i] * y);
            k2--;
        }
    }
    return (res >= k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            p[i] /= 100;
        }
        cin >> x >> a >> y >> b >> k;
        sort(p + 1, p + 1 + n, greater<long long>());
        int l = 1, r = n, ans = -1;
        c = a * b / __gcd(a, b);
        if (x < y) {
            swap(a, b);
            swap(x, y);
        }
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
