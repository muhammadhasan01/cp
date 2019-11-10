#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;
int n, m;
long long c[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        c[a] += k;
        c[b + 1] -= k;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        c[i] += c[i - 1];
        ans = max(ans, c[i]);
    }
    cout << ans << '\n';

    return 0;
}
