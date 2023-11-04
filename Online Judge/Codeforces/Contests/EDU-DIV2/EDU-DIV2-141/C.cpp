#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    if (sum <= m) {
        cout << 1 << '\n';
        return;
    }
    sort(b.begin() + 1, b.end());
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1] + b[i];
    }
    int ans = n + 1;
    for (int take = 1; take < n; take++) {
        int minSum = pre[take];
        int curSum = minSum + max(0, a[take + 1] - b[take]);
        if (curSum <= m) {
            ans = min(ans, n - take);
        } else if (minSum <= m) {
            ans = min(ans, n - take + 1);
        }
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