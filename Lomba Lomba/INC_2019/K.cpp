#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            odd++;
        } else {
            even++;
        }
    }

    if (odd > even) {
        cout << even + (odd - even) / 2 << '\n';
    } else if (odd == even) {
        cout << even << '\n';
    } else {
        cout << odd << '\n';
    }

    return 0;
}
