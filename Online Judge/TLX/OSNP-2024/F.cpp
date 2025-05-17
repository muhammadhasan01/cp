#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += i;
    }
    if (n == 1) {
        cout << ans << '\n';
        return 0;
    }
    int x = m + 2;
    for (int i = 2; i <= n; i++, x += 2) {
        ans += x;
    }
    cout << ans << '\n';
    
    return 0;
}