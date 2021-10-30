#include <bits/stdc++.h>

using namespace std;

const long long INF = 3e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    while (m--) {
        long long x, y;
        cin >> x >> y;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        long long ans = INF;
        if (pos - 1 >= 0) {
            long long res = (x - a[pos - 1]) + max(0LL, y - (sum - a[pos - 1]));
            ans = min(ans, res);
        }
        if (pos < n) {
            long long res = max(0LL, y - (sum - a[pos]));
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}