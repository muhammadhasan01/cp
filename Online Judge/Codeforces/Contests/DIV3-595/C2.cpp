#include <bits/stdc++.h>

using namespace std;

long long pre[45];

int q;
long long n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0] = 1;
    for (int i = 1; i <= 39; i++) {
        pre[i] = 3 * pre[i - 1];
    }

    cin >> q;
    while (q--) {
        cin >> n;

        long long ans = 0;
        for (int i = 39; i >= 0; i--) {
            long long cur = (pre[i] - 1) / 2;
            if (cur >= n) {
                continue;
            } else {
                ans += pre[i];
                n -= pre[i];
            }
            if (n <= 0) break;
        }
        cout << ans << '\n';
    }

    return 0;
}
