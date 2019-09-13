#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        mp[x] = max(mp[x], y);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        mp[x] = max(mp[x], y);
    }
    long long ans = 0;
    for (auto e : mp) {
        ans += (1LL) * e.second;
    }
    cout << ans << '\n';

    return 0;
}
