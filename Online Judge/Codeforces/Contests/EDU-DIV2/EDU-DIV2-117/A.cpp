#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int sum = x + y;
    if (sum & 1) {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    sum /= 2;
    int takeX = min(x, sum);
    x -= takeX;
    sum -= takeX;
    int takeY = min(y, sum);
    y -= takeY;
    sum -= takeY;
    cout << x << ' ' << y << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}