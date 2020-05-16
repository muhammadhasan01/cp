#include <bits/stdc++.h>

using namespace std;

int tc;
int q;
long long a, b;
long long l, r;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> q;
        if (a > b) swap(a, b);
        long long lcm = a * b / __gcd(a, b);
        for (int t = 1; t <= q; t++) {
            cin >> l >> r;
            long long p1 = (r / lcm);
            long long p2 = ((l - 1) / lcm);
            long long r1 = r % lcm;
            long long r2 = (l - 1) % lcm;
            long long ans = r - l + 1;
            for (int i = 0; i < b; i++) {
                long long cur = (p1 - p2);
                if (i <= r1) cur++;
                if (i <= r2) cur--;
                ans -= cur;
            }
            cout << ans << (t == q ? '\n' : ' ');
        }
    }

    return 0;
}