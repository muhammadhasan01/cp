#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c;
        long long ans = 2e18;
        for (auto e : {-1, 0, 1}) {
            for (auto el : {-1, 0, 1}) {
                for (auto ele : {-1, 0, 1}) {
                    long long x = a + e;
                    long long y = b + el;
                    long long z = c + ele;
                    ans = min(ans, abs(x - y) + abs(y - z) + abs(x - z));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
