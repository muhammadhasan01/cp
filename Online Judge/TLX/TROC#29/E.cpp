#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = __gcd(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long cur = __gcd(pre[i - 1], suf[i + 1]) + a[i];
        ans = max(ans, cur); 
    }
    cout << ans << '\n';
    
    return 0;
}