#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    auto getValue = [&](int num) -> int {
        vector<int> A = a;
        A[0] = num;
        sort(A.begin(), A.end());

        auto can = [&](int k) -> bool {
            for (int i = 0, j = k; j < n; i++, j++) {
                if (A[i] >= b[j]) {
                    return false;
                }
            }
            return true;
        };

        int l = 0, r = n, ret = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                r = mid - 1;
                ret = mid;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    };

    long long ans = 0;
    for (int st = 1; st <= m; st++) {
        int val = getValue(st);
        int l = st, r = m, ed = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (getValue(mid) == val) {
                l = mid + 1;
                ed = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += 1LL * val * (ed - st + 1);
        st = ed;
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