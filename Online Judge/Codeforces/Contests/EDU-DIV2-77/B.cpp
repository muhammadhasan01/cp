#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        long long dif = a - b;
        if (b < dif) {
            cout << "NO" << '\n';
        } else {
            cout << ((b - dif) % 3 == 0 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
