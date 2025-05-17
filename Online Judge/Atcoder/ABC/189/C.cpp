#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mn = a[i];
        for (int j = i, len = 1; j < n; j++, len++) {
            mn = min(mn, a[j]);
            ans = max(ans, len * mn);
        }
    }
    cout << ans << '\n';
        
    return 0;
}