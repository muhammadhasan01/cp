#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> d(n);
    d[0] = -a[0];
    for (int i = 1; i < n; i++) {
        d[i] = a[i - 1] - a[i];
    }
    long long ans = 0;
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > 0) {
            sum += d[i];
            ans += d[i];
        } else if (d[i] < 0) {
            ans += abs(d[i]);
        }
    }
    d[0] += sum;
    ans += abs(d[0]);
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