#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        cout << cur + INF << " \n"[i == n - 1];
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