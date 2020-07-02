#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k;
long long x, a[N];
long long pre[N], suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long xp = 1;
    while (k > 0) {
        if (k & 1) xp *= x;
        k >>= 1;
        x = (x * x);
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = (a[i] | pre[i - 1]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = (a[i] | suf[i + 1]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (pre[i - 1]) | (a[i] * xp) | (suf[i + 1]));
    }
    cout << ans << '\n';

    return 0;
}
