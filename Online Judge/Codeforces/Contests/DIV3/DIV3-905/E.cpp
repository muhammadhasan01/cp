#include <bits/stdc++.h>

using namespace std;

const int K = 30;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> two(n);

    auto can = [&](int x, int i) -> bool {
        int mn = min(two[i - 1], x);
        int lft = two[i - 1] - mn;
        int rgt = x - mn;
        long long L = (1LL << min(K, lft)) * a[i - 1];
        long long R = (1LL << min(K, rgt)) * a[i];
        return R >= L;
    };

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int l = max(0, two[i - 1] - K), r = two[i - 1] + K;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid, i)) {
                r = mid - 1;
                two[i] = mid;
            } else {
                l = mid + 1;
            }
        }
        ans += two[i];
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}