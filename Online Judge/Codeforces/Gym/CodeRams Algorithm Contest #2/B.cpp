#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, k;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<>());
    long long ans = 0;
    for (int i = 1; i <= 1 + (m - 1) * k; i++) {
        ans += a[i];
    }
    cout << ans << '\n';

    return 0;
}