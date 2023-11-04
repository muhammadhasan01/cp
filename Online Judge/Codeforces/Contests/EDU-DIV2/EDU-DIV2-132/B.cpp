#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n + 2);
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + max(0LL, a[i - 1] - a[i]);
    }
    vector<long long> suf(n + 2);
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = suf[i + 1] + max(0LL, a[i + 1] - a[i]);
    }
    while (m--) {
        int s, t;
        cin >> s >> t;
        if (s < t) {
            cout << pre[t] - pre[s] << '\n';
        } else {
            cout << suf[t] - suf[s] << '\n';
        }
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