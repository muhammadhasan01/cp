#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    auto isWin = [&](vector<int> x, vector<int> y) -> bool {
        priority_queue<int> X, Y;
        for (int val : x) {
            X.emplace(val);
        }
        for (int val : y) {
            Y.emplace(val);
        }
        while (true) {
            if (X.empty()) {
                return false;
            }
            if (Y.empty()) {
                return true;
            }
            int vx = X.top();
            int vy = Y.top();
            X.pop();
            Y.pop();
            if (vx >= vy) {
                return true;
            }
            if (vx < vy) {
                return false;
            }
        }
        return true;
    };

    cout << (isWin(a, b) ? "Alice" : "Bob") << '\n';
    cout << (isWin(b, a) ? "Bob" : "Alice") << '\n';
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