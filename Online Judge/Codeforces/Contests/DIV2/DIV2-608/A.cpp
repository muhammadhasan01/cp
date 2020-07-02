#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d, e, f;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d >> e >> f;
    long long ans = 0, cur = 0;
    for (long long i = 0; i <= min(a, d); i++) {
        long long now = i * e + f * min(min(b, c), max(0LL, d - i));
        ans = max(ans, now);
    }
    cout << ans << '\n';

    return 0;
}
