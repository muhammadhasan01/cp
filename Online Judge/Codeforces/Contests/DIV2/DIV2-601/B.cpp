#include <bits/stdc++.h>

using namespace std;

int tc;
int n, m, sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        if (m < n || n == 2) {
            cout << -1 << '\n';
            continue;
        }
        cout << 2 * sum << '\n';
        for (int i = 1; i < n; i++) {
            cout << i << " " << i + 1 << '\n';
        }
        cout << 1 << " " << n << '\n';
    }

    return 0;
}
