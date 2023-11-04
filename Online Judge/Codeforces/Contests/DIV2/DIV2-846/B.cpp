#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n + 2);
    vector<long long> suf(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, __gcd(pre[i], suf[i + 1]));
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