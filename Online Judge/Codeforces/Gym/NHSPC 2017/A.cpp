#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    auto ceil = [&](int x, int y) {
        return (x + y - 1) / y;
    };
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int up = ceil(x, m) * m;
        ans += (up - x);
    }
    cout << ans << '\n';
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