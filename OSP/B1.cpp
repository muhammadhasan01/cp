#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sa = 0;
    for (int i = 0; i < n; i++) {
        sa += a[i];
    }
    long long sb = 0;
    for (int i = 0; i < m; i++) {
        sb += b[i];
    }
    int x = n, y = m;
    long long ans = 0;
    while (1) {
        if (sa * y > sb * x) {
            break;
        }
        int last = b[y - 1];
        while (y >= 1 && b[y - 1] == last) {
            sa += b[y - 1];
            sb -= b[y - 1];
            ans += b[y - 1];
            x++;
            y--;
        }
        if (y == 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}