#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e16;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto can = [&](long long x) -> bool {
        long long hp = x;
        for (int i = 0; i < n; i++) {
            hp += a[i];
            if (hp <= 0) {
                return false;
            }
        }
        return true;
    };

    long long l = 0, r = INF, ans = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1LL;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}