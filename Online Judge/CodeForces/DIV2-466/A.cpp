#include <bits/stdc++.h>
using namespace std;

int n, d;
int a[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int dif = a[j] - a[i];
            int len = j - i + 1;
            if (dif <= d) ans = min(ans, n - len);
        }
    }
    cout << ans << '\n';

    return 0;
}
