#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    long long sum = 0;
    long long even = 0;
    for (int i = n; i >= 1; i--) {
        if (i % 2 == 1) {
            if (a[i] > 0) {
                sum += (a[i] + even);
                even = 0;
                ans = max(ans, sum);
            } else {
                ans = max(ans, sum + a[i] + even);
            }
        } else {
            ans = max(ans, sum + even);
            if (a[i] > 0) {
                even += a[i];
            }
        }
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