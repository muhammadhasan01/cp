#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int l[N], r[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    long long ans = n;
    for (int i = 1; i <= n; i++) ans += (1LL) * max(l[i], r[i]);
    cout << ans << '\n';

    return 0;
}
