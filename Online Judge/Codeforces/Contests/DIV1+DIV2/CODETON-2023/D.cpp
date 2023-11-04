#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

void solve() {
    int q;
    cin >> q;
    long long l = -INF, r = INF;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            long long a, b, n;
            cin >> a >> b >> n;
            long long dif = a - b;
            long long cl = -1, cr = -1;
            if (n == 1) {
                cr = a;
                cl = 1;
            } else if (n > 1) {
                cr = dif * (n - 1) + a;
                cl = cr - dif + 1;
            }
            if (cr < l || cl > r) {
                cout << 0 << " ";
            } else {
                cout << 1 << " ";
                r = min(r, cr);
                l = max(l, cl);
            }
        } else if (tp == 2) {
            long long a, b;
            cin >> a >> b;
            if (r == INF) {
                cout << -1 << " ";
                continue;
            }
            if (a >= r) {
                cout << 1 << " ";
                continue;
            }
            long long dif = a - b;
            long long h = r - a;
            long long d = (h + dif - 1) / dif;
            long long cr = d * dif + a;
            long long cl = cr - dif + 1;
            if (l < cl) {
                cout << -1 << " ";
            } else {
                cout << d + 1 << " ";
            }
        }
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}