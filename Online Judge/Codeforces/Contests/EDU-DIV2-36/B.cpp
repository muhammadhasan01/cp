#include<bits/stdc++.h>
using namespace std;

int n, pos, l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> pos >> l >> r;
    if (pos <= l) {
        cout << (l - pos) + (l > 1) + (r < n) * (r - l + 1)  << '\n';
    } else if (l < pos && pos < r) {
        if (l == 1 && r == n) {
            cout << 0 << '\n';
        } else if (l == 1) {
            cout << (r - pos + 1) << '\n';
        } else if (r == n) {
            cout << (pos - l + 1) << '\n';
        } else {
            cout << min(pos - l, r - pos) + (r - l) + 2 << '\n';
        }
    } else if (pos >= r) {
        cout << (pos - r) + (r < n) + (l > 1) * (r - l + 1) << '\n';
    }

    return 0;
}
