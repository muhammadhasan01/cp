#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e14;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    auto can = [&](long long x) -> bool {
        vector<long long> c(n);
        vector<vector<int>> pos(k + 1);
        for (int i = 0; i < n; i++) {
            long long t = a[i] / b[i] + 1;
            if (t >= k) {
                continue;
            }
            c[i] = a[i] % b[i];
            pos[t].emplace_back(i);
        }
        for (int t = 1, idx = 0; t <= k; t++) {
            while (idx < k && pos[idx].empty()) {
                idx++;
            }
            if (idx == k) {
                return true;
            }
            if (t > idx) {
                return false;
            }
            int id = pos[idx].back();
            if (c[id] + x < b[id]) {
                c[id] += x;
                continue;
            }
            pos[idx].pop_back();
            long long nt = (c[id] + x) / b[id];
            c[id] = (c[id] + x) % b[id];
            if (idx + nt < k) {
                pos[idx + nt].emplace_back(id);
            }
        }
        return true;
    };
    long long l = 0, r = INF, ans = -1;
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
    
    return 0;
}