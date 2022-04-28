#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            mp[sum] = i;
        }
    }
    int cur = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur += a[i];
        if (mp.count(cur) && mp[cur] < i) {
            ans = (mp[cur] + 1) + (n - i);
        }
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