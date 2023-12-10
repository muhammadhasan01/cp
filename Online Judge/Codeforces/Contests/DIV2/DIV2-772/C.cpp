#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[n - 1] > a[n]) {
        cout << -1 << '\n';
        return;
    }
    priority_queue<tuple<long long, int, int>> pq;
    pq.emplace(-(a[n - 1] - a[n]), n - 1, n);
    pair<long long, int> mx = {a[n], n};
    vector<tuple<int, int, int>> ans;
    for (int i = n - 2; i >= 1; i--) {
        auto [_, y, z] = pq.top();
        long long cur = a[y] - a[z];
        if (a[i] > cur) {
            a[i] = cur;
            ans.emplace_back(i, y, z);
        }
        if (a[i] > a[i + 1]) {
            cout << -1 << '\n';
            return;
        }
        mx = max(mx, {a[i + 1], i + 1});
        pq.emplace(-(a[i] - a[mx.second]), i, mx.second);
    }
    cout << (int) ans.size() << '\n';
    for (auto& [x, y, z] : ans) {
        cout << x << ' ' << y << ' ' << z << '\n';
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