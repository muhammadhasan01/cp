#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> mx(k);
    for (int i = 0; i < n; i++) {
        mx[(i % k)] = max(mx[(i % k)], a[i]);
    }
    cout << accumulate(mx.begin(), mx.end(), 0LL) << '\n';
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