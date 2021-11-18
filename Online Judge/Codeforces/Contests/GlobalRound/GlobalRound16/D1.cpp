#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        p[i] = make_pair(x, i);
    }
    sort(p.begin(), p.end(), [&](auto& x, auto& y) {
        if (x.first == y.first) {
            return x.second > y.second;
        }
        return x.first < y.first;
    });
    vector<int> a(m);
    for (int i = 0, j = 0; i < m; i++) {
        a[p[i].second] = j++;
    }
    int ans = 0;
    vector<int> cnt(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < a[i]; j++) {
            ans += cnt[j];
        }
        cnt[a[i]]++;
    }
    cout << ans << '\n';
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