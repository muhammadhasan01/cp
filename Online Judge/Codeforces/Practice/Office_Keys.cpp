#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, k, p;
int a[N], b[N];
long long ans = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + k);
    for (int i = 1; i <= k - n + 1; i++) {
        long long cur = 0;
        for (int j = 1; j <= n; j++) {
            cur = max(cur, (1LL) * abs(b[i + j - 1] - a[j]) + (1LL) * abs(b[i + j - 1] - p));
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}
