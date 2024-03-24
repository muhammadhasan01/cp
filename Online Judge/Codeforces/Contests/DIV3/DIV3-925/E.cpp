#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int y = 0;
        int val = x;
        while (val % 10 == 0) {
            val /= 10;
            y++;
        }
        a[i] = {y, x};
    }
    sort(a.rbegin(), a.rend());
    int len = 0;
    for (int i = 0; i < n; i++) {
        auto [y, x] = a[i];
        if (i % 2 == 0) {
            len += to_string(x).length() - y;
        } else {
            len += to_string(x).length();
        }
    }
    cout << (len >= m + 1 ? "Sasha" : "Anna") << '\n';
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