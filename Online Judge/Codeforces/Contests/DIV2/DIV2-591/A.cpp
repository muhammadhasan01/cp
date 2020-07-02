#include <bits/stdc++.h>
using namespace std;

int q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        if (x < 4) {
            cout << 4 - x << '\n';
        } else {
            cout << (x & 1 ? 1 : 0) << '\n';
        }
    }

    return 0;
}
