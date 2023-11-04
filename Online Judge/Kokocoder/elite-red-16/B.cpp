#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    auto F = [&](int x) -> long long {
        return 1LL * x * (x + 1) / 2;
    };

    auto get = [&](int l, int r, int x) -> long long {
        int len = r - l + 1;
        if (x >= len) {
            return F(x) - F(x - len);
        }
        return F(x) + (len - x);
    };

    auto can = [&](int x) -> bool {
        long long lft = get(1, k, x);
        long long rgt = get(k, n, x);
        long long cnt = lft + rgt - x;
        return cnt <= m;
    };

    int l = 1, r = m, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}