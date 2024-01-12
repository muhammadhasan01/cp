#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> b(n);
    long long M = 1;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        M = (M * b[i]);
    }
    if (2023 % M != 0) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    cout << 2023 / M;
    if (k == 1) {
        cout << '\n';
    } else {
        cout << " ";
        for (int i = 0; i < k - 1; i++) {
            cout << 1 << " \n"[i == k - 2];
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