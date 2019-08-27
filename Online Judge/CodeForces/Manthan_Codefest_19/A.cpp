#include <bits/stdc++.h>
using namespace std;

int tc;
int a, b, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> n;
        if (n % 3 == 0) {
            cout << a << '\n';
        } else if (n % 3 == 1 ) {
            cout << b << '\n';
        } else if (n % 3 == 2) {
            int cur = a ^ b;
            cout << cur << '\n';
        }
    }

    return 0;
}
