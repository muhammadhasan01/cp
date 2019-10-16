#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, x, l, y;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool okx = false, oky = false;
    for (int i = 1; i <= n; i++) {
        if (binary_search(a + i + 1, a + 1 + n, a[i] + x)) {
            okx = true;
        }
        if (binary_search(a + i + 1, a + 1 + n, a[i] + y)) {
            oky = true;
        }
        if (okx && oky) break;
    }
    if (okx && oky) {
        cout << 0 << '\n';
    } else if (okx) {
        cout << 1 << '\n' << y << '\n';
    } else if (oky) {
        cout << 1 << '\n' << x << '\n';
    } else {
        int cur, pos;
        for (int i = 1; i <= n; i++) {
            cur = a[i] + x;
            if (cur < l) {
                pos = lower_bound(a + 1, a + 1 + n, cur + y) - a;
                if (pos <= n && a[pos] == cur + y) {
                    cout << 1 << '\n' << cur << '\n';
                    return 0;
                }
                pos = lower_bound(a + 1, a + 1 + n, cur - y) - a;
                if (pos <= n && a[pos] == cur - y) {
                    cout << 1 << '\n' << cur << '\n';
                    return 0;
                }
            }
            cur = a[i] - x;
            if (cur > 0) {
                pos = lower_bound(a + 1, a + 1 + n, cur + y) - a;
                if (pos <= n && a[pos] == cur + y) {
                    cout << 1 << '\n' << cur << '\n';
                    return 0;
                }
                pos = lower_bound(a + 1, a + 1 + n, cur - y) - a;
                if (pos <= n && a[pos] == cur - y) {
                    cout << 1 << '\n' << cur << '\n';
                    return 0;
                }
            }
        }
        cout << 2 << '\n' << x << ' ' << y << '\n';
    }

    return 0;
}
