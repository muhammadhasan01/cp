#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = -INF;
    a[n + 1] = INF;
    vector<long long> pre(n + 2);
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
            pre[i] = 1 + pre[i - 1];
        } else {
            pre[i] = a[i] - a[i - 1] + pre[i - 1];
        }
    }
    vector<long long> suf(n + 2);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] - a[i - 1] > a[i + 1] - a[i]) {
            suf[i] = 1 + suf[i + 1];
        } else {
            suf[i] = a[i + 1] - a[i] + suf[i + 1];
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            cout << pre[x] - pre[y] << '\n';
        } else {
            cout << suf[x] - suf[y] << '\n';
        }
    }
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