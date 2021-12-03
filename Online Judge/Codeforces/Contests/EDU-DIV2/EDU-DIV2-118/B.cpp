#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    } 
    sort(a.begin(), a.end());
    int tgt = n / 2;
    int cur = 0;
    vector<pair<int, int>> ans(tgt);
    for (int i = 1; i < n; i++) {
        ans[cur++] = make_pair(a[i], a[0]);
        if (cur == tgt) {
            break;
        }
    }
    for (auto& [x, y] : ans) {
        cout << x << ' ' << y << '\n'; 
    }
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