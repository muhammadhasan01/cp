#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum <= k) {
        cout << 0 << '\n';
        return;
    }
    long long ans = sum - k;
    long long add = 0;
    for (int i = n - 1, j = 2; i > 0; i--, j++) {
        add += a[i] - a[0];
        // sum - j * X - add <= K
        // (sum - k - add) / j <= X
        long long X = max(0LL, (sum - k - add + j - 1) / j);
        long long op = X + 1LL * (j - 1);
        ans = min(ans, op);
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