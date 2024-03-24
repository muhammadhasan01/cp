#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> S(n + 1);
    vector<long long> C(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        S[i] = (x - 1) + S[i - 1];
        C[i] = (x == 1) + C[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "NO" << '\n';
            continue;
        }
        long long numOne = C[r] - C[l - 1];
        long long sum = S[r] - S[l - 1];
        cout << (sum >= numOne ? "YES" : "NO") << '\n'; 
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