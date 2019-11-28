#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n, m;
ll a[N];

bool can(ll x) {
    int cnt = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - a[last] > x) {
            if (a[i - 1] - a[last] > x) {
                return false;
            }
            last = i - 1;
            cnt++;

        }
    }
    if (last != n) {
        if (a[n] - a[last] > x) return false;
        cnt++;
    }
    return (cnt <= m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ll l = 0, r = 1e14, ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
