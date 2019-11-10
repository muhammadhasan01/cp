#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if (a == b) {
        int x = 10 * a;
        cout << x << " " << x + 1 << '\n';
    } else if (a + 1 == b) {
        int x = 10 * a + 9;
        cout << x << " " << x + 1 << '\n';
    } else if (a == 9 && b == 1) {
        cout << 9 << " " << 10 << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
