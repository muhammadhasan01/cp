#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int gg = 0;
    for (int i = 1; i <= n; i++) {
        gg = __gcd(a[i], gg);
    }
    if (gg == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> X = {{n}, {n - 1}, {n - 1, n}};
    for (vector<int>& x : X) {
        vector<int> b = a;
        for (int i : x) {
            b[i] = __gcd(b[i], i);
        }
        int g = 0;
        for (int i = 1; i <= n; i++) {
            g = __gcd(b[i], g);
        }
        if (g == 1) {
            int cost = 0;
            for (int i : x) {
                cost += n - i + 1;
            }
            cout << cost << '\n';
            return;
        }
    }
    assert(false);
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