#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 3;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        vector<int> xs, ys;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            xs.emplace_back(a[j].first);
            ys.emplace_back(a[j].second);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        bool isHorizontal = (xs[0] < a[i].first) && (xs[1] > a[i].first);
        bool isVertical = (ys[0] < a[i].second) && (ys[1] > a[i].second);
        if (isHorizontal || isVertical) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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