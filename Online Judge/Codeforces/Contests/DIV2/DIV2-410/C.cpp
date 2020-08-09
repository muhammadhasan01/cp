#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    if (g > 1) {
        cout << "YES" << '\n';
        cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 == 0 || a[i + 1] % 2 == 0) continue;
        ++ans;
        a[i] ^= 1, a[i + 1] ^= 1; ++i;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) continue;
        ans += 2;
    }
    cout << "YES" << '\n';
    cout << ans << '\n';

    return 0;
}