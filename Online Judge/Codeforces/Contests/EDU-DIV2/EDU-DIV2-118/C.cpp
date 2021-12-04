#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto can = [&](long long k) {
        long long val = 0;
        int pos = 0;
        while (pos < n) {
            long long place = a[pos] + k - 1;
            int l = pos + 1, r = n - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[mid] <= place) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at == -1) {
                val += k;
                pos++;
            } else {
                val += a[at] - a[pos];
                pos = at;
            }
            if (val >= h) {
                return true;
            }
        }
        return val >= h;
    };
    long long l = 1, r = h, ans = h;
    while (l <= r) {
        long long mid = (l + r) >> 1;
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