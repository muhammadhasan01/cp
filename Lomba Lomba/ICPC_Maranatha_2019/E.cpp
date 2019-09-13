#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int tc;
int n, a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (n == 2) {
            if (a[1] != a[2]) {
                cout << "false" << '\n';
            } else {
                cout << "true" << '\n';
            }
            continue;
        }

        sort(a + 1, a + 1 + n);
        int sum = 0;
        for (int i = 1; i <= n - 1; i++) {
            sum += a[i];
        }
        cout << (sum >= a[n] ? "true" : "false") << '\n';
    }

    return 0;
}
