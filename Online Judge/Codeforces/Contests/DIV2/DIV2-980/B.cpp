#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long k;
    cin >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long cur = 0;
    int ans = 0;
    for (int i = 0, j = n; i < n; i++, j--) {
        if (i > 0) {
            a[i] -= a[i - 1];
        }
        cur += 1LL * a[i] * j;
        if (cur >= k) {
            break;
        }
        ++ans;
    }
    cout << k + ans << '\n';
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