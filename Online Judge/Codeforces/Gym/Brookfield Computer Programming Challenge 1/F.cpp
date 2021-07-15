#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, u;
    cin >> n >> u;
    vector<int> l(u), r(u);
    for (int i = 0; i < u; i++) {
        cin >> l[i] >> r[i];
    }
    auto check = [&](int x) -> bool {
        if (x <= 0 || x > n) {
            return false;
        }
        for (int i = 0; i < u; i++) {
            if (l[i] <= x && x <= r[i]) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < u; i++) {
        if (check(l[i] - 1)) {
            cout << l[i] - 1 << '\n';
            return 0;
        }
        if (check(r[i] + 1)) {
            cout << r[i] + 1 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';

    return 0;
}