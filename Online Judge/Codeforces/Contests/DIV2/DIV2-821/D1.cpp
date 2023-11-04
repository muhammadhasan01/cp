#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            pos.emplace_back(i);
        }
    }
    int len = (int) pos.size();
    if (len == 0) {
        cout << 0 << '\n';
        return;
    }
    if (len & 1) {
        cout << -1 << '\n';
        return;
    }
    if (len > 2) {
        cout << 1LL * (len / 2) * y << '\n';
        return;
    }
    if (pos[0] + 1 == pos[1]) {
        cout << min(x, 2 * y) << '\n';
    } else {
        cout << y << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}