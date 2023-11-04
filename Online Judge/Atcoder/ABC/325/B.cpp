#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> w(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> x[i];
    }
    int ans = 0;
    for (int X = 0; X < 24; X++) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            int st = (X + x[i]) % 24;
            if (9 <= st && st <= 17) {
                res += w[i];
            }
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
    
    return 0;
}