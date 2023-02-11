#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    int cur = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] <= cur && cur <= r[i]) {
            continue;
        }
        if (cur < l[i]) {
            ans += 1LL * (l[i] - cur);
            cur = l[i];
        } else if (cur > r[i]) {
            ans += 1LL * (cur - r[i]);
            cur = r[i];
        }
    }
    cout << ans << '\n';
    
    return 0;
}