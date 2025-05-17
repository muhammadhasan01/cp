#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    p[0] = {1, 1};
    p[1] = {1, 2};
    for (int i = n; i > 2; i--) {
        p[i - 1] = {i, i};
    }
    for (int i = 0; i < n; i++) {
        cout << p[i].first << " " << p[i].second << '\n';
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