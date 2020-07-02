#include <bits/stdc++.h>
using namespace std;

int tc;
int a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c;
        int ans = 0;
        while (c > 1 && b > 0) {
            ans += 3;
            c -= 2;
            b--;
        }
        while (a > 0 && b > 1) {
            ans += 3;
            b -= 2;
            a--;
        }
        cout << ans << '\n';
    }

    return 0;
}
