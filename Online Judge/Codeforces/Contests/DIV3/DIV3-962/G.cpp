#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> pre(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        long long x = rng();
        pre[a] ^= x;
        pre[b] ^= x;
    }
    map<long long, int> mp;
    int freq = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            pre[i] ^= pre[i - 1];
        }
        freq = max(freq, ++mp[pre[i]]);
    }
    cout << n - freq << '\n';
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