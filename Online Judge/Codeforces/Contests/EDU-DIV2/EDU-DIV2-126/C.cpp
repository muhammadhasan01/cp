#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n + 1);
    long long mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        mx = max(mx, h[i]);
    }

    auto can = [&](long long x) -> bool {
        long long two = x / 2;
        long long one = x - two;
        for (long long need : {mx, mx + 1, mx + 2}) {
            bool flag = true;
            for (int i = 1; i <= n; i++) {
                long long dif = need - h[i];
                {
                    long long take = min(two, dif / 2);
                    dif -= take * 2;
                    two -= take;
                }
                {
                    long long take = min(one, dif);
                    dif -= take;
                    one -= take;
                }
                if (dif > 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
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