#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) {
        cin >> x >> y;
    }

    auto inverse = [&](vector<int>& X) {
        int len = (int) X.size();
        int cnt = 0;
        for (int i = 0; i + 1 < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (X[i] > X[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    };

    sort(a.begin(), a.end(), [&](auto& lhs, auto& rhs) {
        vector<int> L = {lhs.first, lhs.second, rhs.first, rhs.second};
        vector<int> R = {rhs.first, rhs.second, lhs.first, lhs.second};
        return inverse(L) > inverse(R);
    });
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i].first << ' ' << a[i].second << " \n"[i == n - 1];
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