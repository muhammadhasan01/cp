#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vals(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int rem = x % k;
        if (rem == 0) {
            rem = k;
        }
        vals[i] = make_pair(rem, i);
    }
    sort(vals.begin(), vals.end(), [&](auto& lhs, auto& rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    });
    vector<int> ans(n);
    int cnt = 0;
    for (auto& [rem, i] : vals) {
        ans[cnt++] = i + 1;
    }
    for (int i = 0; i < n; i++) {
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