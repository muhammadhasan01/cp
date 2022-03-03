#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int val = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        val ^= a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((val ^ a[i]) < a[i]) {
            ans++;
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
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}