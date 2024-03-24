#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    set<int> X, Y;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int cur = 0;
        if (X.find(x) == X.end()) {
            X.emplace(x);
            cur += m - (int) Y.size();
        }
        if (Y.find(y) == Y.end()) {
            Y.emplace(y);
            cur += n - (int) X.size();
        }
        cout << cur << '\n';
    }
    
    return 0;
}