#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    if (m % n != 0) {
        cout << -1 << '\n';
        return 0;
    }
    m /= n;
    int ans = 0;
    for (int d : {3, 2}) {
        while (m % d == 0) {
            m /= d;
            ans++;
        }
    }
    if (m > 1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
    
    return 0;
}