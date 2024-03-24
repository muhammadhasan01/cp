#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    long long ans = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans += mp[{(x - a % x) % x, a % y}];
        mp[{a % x, a % y}]++;
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