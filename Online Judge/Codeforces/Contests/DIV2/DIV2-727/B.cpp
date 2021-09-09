#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        int num = cc - 'a' + 1;
        pre[i] = pre[i - 1] + num;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
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