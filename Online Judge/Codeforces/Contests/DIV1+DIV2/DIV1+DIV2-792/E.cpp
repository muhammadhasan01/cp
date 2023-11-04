#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int unique = (int) mp.size();
    int mex = 0;
    for (int x = 0, y = k; x < n; x++) {
        if (mp.count(x)) {
            mex = x + 1;
            continue;
        }
        if (y > 0) {
            mex = x + 1;
            --y;
            continue;
        }
        break;
    }
    int ans = unique - mex;
    vector<pair<int, int>> op;
    for (auto& [val, cnt] : mp) {
        if (val < mex) {
            op.emplace_back(2, cnt);
        } else {
            op.emplace_back(1, cnt);
        }
    }
    sort(op.begin(), op.end());
    for (auto [tp, cnt] : op) {
        if (tp == 1) {
            while (k > 0 && cnt > 1) {
                ans++;
                cnt--;
                k--;
            }
            while (k > 0 && cnt == 1) {
                cnt--;
                k--;
            }
        } else if (tp == 2) {
            while (k > 0 && cnt > 1) {
                ans++;
                cnt--;
                k--;
            }
        }
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