#include <bits/stdc++.h>

using namespace std;

int tc;
long long r, b, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> r >> b >> k;
        if (r > b) swap(r, b);
        long long g = __gcd(r, b);
        cout << (r * (k - 1LL) + g < b ? "REBEL" : "OBEY") << '\n';
    }

    return 0;
}
