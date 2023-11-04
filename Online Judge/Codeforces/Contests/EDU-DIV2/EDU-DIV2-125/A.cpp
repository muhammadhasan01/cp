#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

set<int> squares;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0 << '\n';
        return;
    }
    int cur = x * x + y * y;
    if (squares.count(cur)) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        int val = i * i;
        squares.emplace(val);
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}