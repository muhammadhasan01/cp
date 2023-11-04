#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mn = INT_MAX;
    while (q--) {
        int x;
        cin >> x;
        if (x >= mn) {
            continue;
        }
        mn = min(mn, x);
        long long cur = (1LL << x);
        long long add = (1LL << (x - 1));
        for (int i = 0; i < n; i++) {
            if (a[i] % cur == 0) {
                a[i] += add;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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