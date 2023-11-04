#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long c, d;
    cin >> n >> c >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = c * n + d;
    int cnt = 0;
    int dup = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || (i > 0 && a[i] != a[i - 1])) {
            ++cnt;
        }
        if (i > 0 && a[i] == a[i - 1]) {
            ++dup;
        }
        long long L = 1LL * (a[i] - cnt) * d + 1LL * dup * c;
        long long R = 1LL * (n - i - 1) * c;
        long long cur = L + R;
        ans = min(ans, cur);
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