#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto melt = [&](int l, int r, int x) -> void {
        if (x == 1) {
            return;
        }
        for (int i = l; i <= r; i++) {
            a[i] = a[i] / x;
        }
    };

    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            melt(l, r, x);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int i = l; i <= r; i++) {
                sum += a[i];
            }
            cout << sum << '\n';
        }
    }
    
    return 0;
}