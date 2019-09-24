#include <bits/stdc++.h>
using namespace std;

int q;
int c, m, x;

int f(int x) {
    if (x <= 1) return 0;
    if (x % 3 == 0 || x % 3 == 1) {
        return (x / 3) * 2;
    } else {
        return ((x + 1) / 3) * 2 - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> c >> m >> x;
        if (c < m) swap(c, m);
        if (x >= m) {
            cout << m << '\n';
        } else {
            m -= x, c -= x;
            int ans = x;
            int dif = c - m;
            int sem = m - dif;
            if (sem < 1) {
                ans += m;
            } else if (sem == 1) {
                ans += (m - 1);
            } else {
                ans += dif + f(sem);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
