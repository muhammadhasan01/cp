#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, p;
    cin >> n >> p;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < p) {
            ans++;
        }
    }
    cout << ans << '\n';
    
    return 0;
}