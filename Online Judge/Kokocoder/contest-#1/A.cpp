#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    int ans = 0;
    for (int i = 0, cur = 0; i < 2 * n; i++) {
        if (a[i] == 1) {
            cur++;
        } else if (a[i] == 0) {
            cur = 0;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    
    return 0;
}