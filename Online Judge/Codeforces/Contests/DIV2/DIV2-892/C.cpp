#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    long long ans = 0;
    for (int pos = n - 1; pos >= 0; pos--) {
        int add = 0;
        for (int i = 0; i < pos; i++) {
            p[i] = ++add;
        }
        for (int i = n - 1; i >= pos; i--) {
            p[i] = ++add;
        }
        long long res = 0;
        long long mx = 0;
        for (int i = 0; i < n; i++) {
            long long cur = 1LL * p[i] * (i + 1);
            res += cur;
            mx = max(mx, cur);
        }
        res -= mx;
        ans = max(ans, res);
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