#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        mp[val]++;
    }
    for (int i = 0; i <= n + 5; i++) {
        if (mp[i] == 0) {
            cout << i << '\n';
            return;
        }
        mp[i + x] += (mp[i] - 1);
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