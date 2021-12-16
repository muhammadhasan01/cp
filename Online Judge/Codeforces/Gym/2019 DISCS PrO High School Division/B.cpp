#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, x;
    cin >> n >> m >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l;
            cin >> l;
            if (__gcd(l, x) > 1) {
                ans++;
            } 
        }
    }
    cout << ans << '\n';
    
    return 0;
}