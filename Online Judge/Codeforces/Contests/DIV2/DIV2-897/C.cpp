#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> X;
    for (int i = 0; i <= 2 * n + 5; i++) {
        X.emplace(i);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = X.find(x);
        if (it == X.end()) {
            continue;
        }
        X.erase(it);
    }
    while (true) {
        int val = *X.begin();
        cout << val << endl;
        int y;
        cin >> y;
        if (y == -1) {
            break;
        }
        if (y == -2) {
            exit(0);
        }
        X.erase(val);
        X.emplace(y);
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