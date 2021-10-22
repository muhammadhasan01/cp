#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<long long> v(3);
    long long m;
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    cin >> m;
    sort(v.begin(), v.end());
    long long mx = 0;
    for (long long x : v) {
        mx += max(0LL, x - 1);
    }
    long long mn = max(0LL, v[2] - v[1] - v[0] - 1);
    cout << ((mn <= m && m <= mx) ? "YES" : "NO") << '\n';
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