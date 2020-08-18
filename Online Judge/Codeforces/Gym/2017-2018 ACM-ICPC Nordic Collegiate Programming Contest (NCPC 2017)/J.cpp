#include <bits/stdc++.h>

using namespace std;

int l, r;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> r;
    if (l == 0 && r == 0) {
        cout << "Not a moose" << '\n';
    } else if (l == r) {
        cout << "Even " << l + r << '\n';
    } else {
        cout << "Odd " << 2 * max(l, r) << '\n';
    }

    return 0;
}