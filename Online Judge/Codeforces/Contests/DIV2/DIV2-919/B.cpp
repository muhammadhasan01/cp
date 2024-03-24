#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long S = accumulate(a.begin(), a.end(), 0LL);
    for (int rep = 0, j = n - 1; rep < x; rep++, j--) {
        S -= a[j] * 2;
    }
    long long ans = S;
    for (int rep = 0, l = n - x - 1, r = n - 1; rep < k; rep++, l--, r--) {
        if (l >= 0) {
            S -= a[l] * 2;
        }
        if (r >= 0) {
            S += a[r];
        }
        ans = max(ans, S);
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