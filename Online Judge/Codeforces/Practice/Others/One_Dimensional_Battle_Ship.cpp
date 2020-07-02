#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k, a;
int m, b[N];

bool cant(int x) {
    vector<int> v(x);
    for (int i = 1; i <= x; i++) v[i - 1] = b[i];
    sort(v.begin(), v.end());
    int ret = 0;
    for (int i = 1; i <= n - a + 1; i++) {
        auto z = lower_bound(v.begin(), v.end(), i);
        if (z != v.end() && *z >= i + a) {
            ret++;
            i += a;
        } else if (z == v.end()) {
            ret++;
            i += a;
        } else {
            i = *z;
        }
    }
    return (ret < k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> a;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int l = 1, r = m, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (cant(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
