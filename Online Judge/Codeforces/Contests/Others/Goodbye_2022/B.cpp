#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << " \n"[i == n];
        }
        return;
    }
    vector<int> p(n + 1);
    int up = n;
    int down = 1;
    for (int l = 1, r = k; l <= n; l += k, r += k) {
        p[l] = up--;
        if (r <= n) {
            p[r] = down++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) {
            p[i] = down++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
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