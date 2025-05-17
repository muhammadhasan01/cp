#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> gears(n);
    for (auto& [l, r] : gears) {
        cin >> l >> r;
    }
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(gears.begin(), gears.end());
    vector<int> mostRight(n);
    for (int i = 0; i < n; i++) {
        mostRight[i] = gears[i].second;
        if (i > 0) {
            mostRight[i] = max(mostRight[i], mostRight[i - 1]);
        }
    }

    auto exists = [&](int L, int R) -> bool {
        int l = 0, r = n - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (gears[mid].first <= L) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        return at != -1 && mostRight[at] >= R;
    };

    vector<int> bound(m);
    {
        multiset<int> ms;
        for (int l = 0, r = -1; l < m; l++) {
            while (r + 1 < m) {
                ms.emplace(a[r + 1]);
                if (exists(*ms.begin(), *ms.rbegin())) {
                    r++;
                    continue;
                }
                ms.erase(ms.find(a[r + 1]));
                break;
            }
            if (ms.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            bound[l] = r;
            ms.erase(ms.find(a[l]));
        }
    }
    vector<int> dp(m + 1);
    dp[m] = 0;
    multiset<int> ms;
    ms.emplace(dp[m]);
    for (int l = m - 1, r = m - 1; l >= 0; l--) {
        while (r > bound[l]) {
            ms.erase(ms.find(dp[r + 1]));
            r--;
        }
        dp[l] = 1 + *ms.begin();
        ms.emplace(dp[l]);
    }
    cout << dp[0] - 1 << '\n';
    
    return 0;
}