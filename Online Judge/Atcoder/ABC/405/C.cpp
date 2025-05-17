#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);_
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    long long ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        ans += a[i] * suf[i + 1];
    }
    cout << ans << '\n';
    
    return 0;
}