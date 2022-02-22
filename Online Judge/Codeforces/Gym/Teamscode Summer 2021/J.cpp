#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> t(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> r[i];
    }
    auto can = [&](long long tim) -> bool {
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (tim < t[i]) {
                continue;
            }
            res += (tim - t[i]) / r[i];
            if (res >= x) {
                return true;
            }
        }
        return false;
    };
    long long L = 0, R = INF, ans = INF;
    while (L <= R) {
        long long mid = (L + R) >> 1;
        if (can(mid)) {
            R = mid - 1;
            ans = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}