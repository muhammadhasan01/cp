#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n % 4 != 0) {
            cout << "NO" << '\n';
            continue;
        }
        int m = n / 2;
        int sum = 0;
        cout << "YES" << '\n';
        for (int i = 1; i <= m; i++) {
            int cur = 2 * i;
            sum += cur;
            cout << cur << " ";
        }
        for (int i = 1; i < m; i++) {
            int cur = 2 * i - 1;
            sum -= cur;
            cout << cur << " ";
        }
        cout << sum << '\n';
    }

    return 0;
}