#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int G = 0, L = INT_MAX;
    vector<int> X;
    for (int i = 0; i < n; i++) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 1) {
            G = max(G, x);
        } else if (tp == 2) {
            L = min(L, x);
        } else if (tp == 3) {
            X.emplace_back(x);
        }
    }
    if (G > L) {
        cout << 0 << '\n';
        return;
    }
    int ans = L - G + 1;
    for (int x : X) {
        if (G <= x && x <= L) {
            ans--;
        }
    }
    cout << ans << '\n';
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