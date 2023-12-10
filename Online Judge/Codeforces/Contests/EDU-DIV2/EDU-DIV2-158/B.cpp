#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= cur) {
            cur = a[i];
            continue;
        }
        ans += (a[i] - cur);
        cur = a[i];
    }
    cout << ans - 1 << '\n';
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