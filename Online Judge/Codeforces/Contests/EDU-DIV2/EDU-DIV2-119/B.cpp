#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long w, h;
    cin >> w >> h;
    long long ans = 0;
    for (int i = 0; i < 4; i++) {
        int k;
        cin >> k;
        vector<long long> v(k);
        for (auto& x : v) {
            cin >> x;
        }
        sort(v.begin(), v.end());
        long long dif = v[k - 1] - v[0];
        long long cur = (i < 2 ? h : w);
        cur = (cur * dif);
        ans = max(ans, cur);
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