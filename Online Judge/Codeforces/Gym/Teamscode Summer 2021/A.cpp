#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (j == i * j) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}