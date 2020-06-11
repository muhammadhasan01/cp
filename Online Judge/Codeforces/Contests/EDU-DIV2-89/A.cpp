#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

int tc;
long long a, b;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        long long dif = b - a;
        long long pos = min(a, dif);
        a -= pos;
        b -= 2 * pos;
        if (a == 0) {
            cout << pos << '\n';
            continue;
        }
        long long ans = pos;
        if (a % 3 == 0) {
            ans += (a / 3) * 2;
        } else if (a % 3 == 1) {
            ans += (a / 3) * 2;
        } else if (a % 3 == 2) {
            ans += ((a + 1) / 3) * 2 - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}