#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    long long ans = 0;
    for (int x = 0; x < min(2 * n + 5, d); x++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == i + 1) {
                cnt++;
            }
        }
        long long res = cnt + (d - (x + 1)) / 2;
        ans = max(ans, res);
        int cur = b[x % k];
        for (int i = 0; i < cur; i++) {
            a[i]++;
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