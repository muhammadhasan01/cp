#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, int>> p(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        p[i] = {x, i};
    }
    sort(p.begin(), p.end());
    vector<int> ans(n);
    vector<long long> pre(n);
    for (int i = 0; i < n; i++) {
        pre[i] = p[i].first;
        if (i > 0) {
            pre[i] += pre[i - 1];
        }
    }
    for (int i = n - 1, lst = n - 1; i >= 0; i--) {
        if (i + 1 < n && p[i + 1].first > pre[i]) {
            lst = i;
        }
        ans[p[i].second] = lst;
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