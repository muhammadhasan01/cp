#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if ((sum + sum) % n != 0) {
        cout << 0 << '\n';
        return;
    }
    long long need = (sum + sum) / n;
    map<long long, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mp[need - a[i]];
        mp[a[i]]++;
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