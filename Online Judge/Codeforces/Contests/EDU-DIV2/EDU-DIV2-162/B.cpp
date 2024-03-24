#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> h(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            x = -x;
        }
        h[x] += a[i];
    }
    long long damage = 0;
    for (int i = 1; i <= n; i++) {
        damage += k;
        if (damage < h[i]) {
            cout << "NO" << '\n';
            return;
        }
        damage -= h[i];
    }
    cout << "YES" << '\n';
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