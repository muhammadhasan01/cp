#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, p;
    cin >> s >> p;
    int n = s.length();
    int m = p.length();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    auto can = [&](int k) -> bool {
        vector<bool> deleted(n);
        for (int i = 0; i < k; i++) {
            deleted[a[i]] = true;
        }
        for (int i = 0, j = 0; i < n; i++) {
            if (deleted[i]) {
                continue;
            }
            if (s[i] == p[j]) {
                ++j;
                if (j == m) {
                    return true;
                }
            }
        }
        return false;
    };

    int l = 0, r = n, ans = -1;
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