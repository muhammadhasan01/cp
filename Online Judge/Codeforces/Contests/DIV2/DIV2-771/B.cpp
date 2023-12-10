#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<queue<int>> parity(K);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        parity[(a[i] & 1)].emplace(a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int p = a[i] & 1;
        if (parity[p].front() != a[i]) {
            cout << "NO" << '\n';
            return;
        }
        parity[p].pop();
    }
    cout << "YES" << '\n';
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