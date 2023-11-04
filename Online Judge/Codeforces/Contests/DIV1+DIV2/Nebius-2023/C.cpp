#include <bits/stdc++.h>

using namespace std;

const int K = 3;

void solve() {
    int n, x, p;
    cin >> n >> x >> p;
    int mx = min(K * n + 5, p);
    for (int it = 1; it <= mx; it++) {
        long long res = 1LL * x + 1LL * it * (it + 1) / 2;
        if (res % n == 0) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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