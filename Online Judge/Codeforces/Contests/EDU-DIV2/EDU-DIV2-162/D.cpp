#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans(n, INF);

    auto work = [&]() -> void {
        vector<long long> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = a[i - 1] + sum[i - 1];
        }
        vector<int> L(n);
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                L[i] = L[i - 1];
            } else {
                L[i] = i;
            }
            int l = 0, r = i - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sum[i] - sum[mid] > a[i]) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at == -1) {
                continue;
            }
            if (at == i - 1) {
                ans[i] = min(ans[i], 1);
                continue;
            }
            int pos = min(at, L[i - 1] - 1);
            if (pos >= 0) {
                ans[i] = min(ans[i], i - pos);
            }
        }
    };

    work();
    reverse(a.begin(), a.end());
    reverse(ans.begin(), ans.end());
    work();
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        if (ans[i] == INF) {
            ans[i] = -1;
        }
        cout << ans[i] << " \n"[i == n - 1];
    }
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