#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(K, {0});
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (v[0].back() > v[1].back()) {
            v[0].swap(v[1]);
        }
        if (x > v[1].back()) {
            v[0].emplace_back(x);
        } else if (x > v[0].back()) {
            v[1].emplace_back(x);
        } else {
            v[0].emplace_back(x);
        }
    }
    int ans = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 1; j + 1 < (int) v[i].size(); j++) {
            if (v[i][j] < v[i][j + 1]) {
                ++ans;
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