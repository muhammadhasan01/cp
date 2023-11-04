#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long lft = a * d;
    long long rgt = b * c;
    if (lft == rgt) {
        cout << 0 << '\n';
        return;
    }
    if (lft > rgt) {
        swap(lft, rgt);
    }
    if (lft == 0 || rgt % lft == 0) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
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