#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a;
    for (int i = 0; i < k; i++) {
        a.emplace_back(i);
    }
    if ((int) a.size() > n) {
        cout << -1 << '\n';
        return;
    }
    while ((int) a.size() < n) {
        a.emplace_back(x == k ? x - 1 : x);
    }
    for (int val : a) {
        if (val > x) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << accumulate(a.begin(), a.end(), 0) << '\n';
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