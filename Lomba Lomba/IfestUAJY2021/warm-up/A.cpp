#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    int x, y;
    while (cin >> x >> y) {
        int ans = 0;
        for (int i = x; i <= y; i++) {
            int rem = i % 10;
            ans += (rem == 3 || rem == 4);
        }
        cout << ans << '\n';
    }
    

    return 0;
}