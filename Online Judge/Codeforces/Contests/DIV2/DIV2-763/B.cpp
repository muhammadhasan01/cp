#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v[i] = make_tuple(r - l, l, r, i);
    }
    sort(v.begin(), v.end());
    vector<tuple<int, int, int>> ans(n);
    vector<bool> done(n + 1);
    for (auto [_, l, r, idx] : v) {
        int cur = -1;
        for (int i = l; i <= r; i++) {
            if (done[i]) {
                continue;
            }
            cur = i;
            break;
        }
        assert(cur != -1);
        ans[idx] = make_tuple(l, r, cur);
        done[cur] = true;
    }
    for (auto [l, r, x] : ans) {
        cout << l << ' ' << r << ' ' << x << '\n';
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