#include <bits/stdc++.h>

using namespace std;

int tc;
long long x[5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        for (int i = 1; i <= 3; i++) {
            cin >> x[i];
        }
        sort(x + 1, x + 1 + 3);
        if (x[1] + x[2] <= x[3]) {
            cout << x[1] + x[2] << '\n';
        } else {
            long long dif = x[3] - x[2];
            cout << x[1] + (x[2] - (x[1] - dif + 1) / 2) << '\n';
        }
    }

    return 0;
}
