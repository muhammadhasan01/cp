#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long f, a, b;
    cin >> n >> f >> a >> b;
    vector<long long> m(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= n; i++) {
        long long cur = min(b, (m[i] - m[i - 1]) * a);
        f -= cur;
        if (f <= 0) {
            cout << "NO" << '\n';
            return;
        }
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