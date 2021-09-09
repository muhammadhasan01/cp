#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18;

void solve() {
    long long p;
    cin >> p;
    vector<long long> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    long long ans = INF;
    for (long long& x : v) {
        long long ceil = (p + x - 1) / x;
        long long up = ceil * x;
        ans = min(ans, up - p);
    }
    cout << ans << '\n';
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