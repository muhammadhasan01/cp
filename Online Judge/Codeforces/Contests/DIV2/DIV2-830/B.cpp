#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<set<int>> pos(K);
    for (int i = 0; i < n; i++) {
        int x = a[i] - '0';
        pos[x].emplace(i);
    }
    int ans = 0;
    bool isInverted = false;
    for (int i = 0; i < n; i++) {
        int x = a[i] - '0';
        if (isInverted) {
            x ^= 1;
        }
        if (x == 1) {
            int y = isInverted ? 1 : 0;
            if (pos[y].upper_bound(i) != pos[y].end()) {
                isInverted = !isInverted;
                ans++;
            }
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