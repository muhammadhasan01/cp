#include <bits/stdc++.h>

using namespace std;

bool can(int x, int y, int c) {
    if (x > y) {
        swap(x, y);
    }
    int ret = x + (y - x) / 2;
    return ret >= c;  
}

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int w, b;
    cin >> w >> b;
    if (can(k1, k2, w) && can(n - k1, n - k2, b)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';   
    }
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