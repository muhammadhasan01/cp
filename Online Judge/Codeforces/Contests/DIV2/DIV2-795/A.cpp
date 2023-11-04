#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[(x & 1)]++;
    }
    cout << min(cnt[0], cnt[1]) << '\n';
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