#include <bits/stdc++.h>

using namespace std;

int tc;
int rest[2];
int cnt[2];
int val[2];

void solve() {
    for (int it = 0; it < 2; it++) {
        cin >> rest[it];
    }
    for (int it = 0; it < 2; it++) {
        cin >> cnt[it];
    }
    for (int it = 0; it < 2; it++) {
        cin >> val[it];
    }
    if (rest[0] < rest[1]) swap(rest[0], rest[1]);
    if (val[1] < val[0]) {
        swap(val[0], val[1]);
        swap(cnt[0], cnt[1]);
    }
    int ans = 0;
    int sum = 0;
    for (int x = 0; x <= cnt[0]; x++) {
        if (sum > rest[0]) break;
        int cur = x;
        int dif = rest[0] - sum;
        int rem = min(cnt[1], dif / val[1]);
        cur += rem;
        int k = cnt[1] - rem;
        int y = cnt[0] - x;
        int z = rest[1];
        rem = min(y, z / val[0]);
        cur += rem;
        z -= rem * val[0];
        rem = min(k, z / val[1]);
        cur += rem;
        ans = max(ans, cur);
        sum += val[0];
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}