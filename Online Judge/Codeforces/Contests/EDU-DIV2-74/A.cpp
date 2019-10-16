#include <bits/stdc++.h>
using namespace std;

int tc;
long long x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> x >> y;
        cout << (x - y == 1 ? "NO" : "YES") << '\n';
    }

    return 0;
}
