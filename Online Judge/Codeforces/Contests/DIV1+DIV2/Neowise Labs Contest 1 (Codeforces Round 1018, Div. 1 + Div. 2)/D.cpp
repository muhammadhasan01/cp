#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<long long, int> mp_x, mp_y;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        long long tx = x;
        long long ty = x + y;
        mp_x[tx]++;
        mp_y[ty]++;
    }
    long long S = 0, sum_x = 0;
    for (auto [x, cnt] : mp_x) {
        sum_x += cnt;
        if (sum_x & 1) {
            S = x;
            break;
        }
    }
    long long T = 0, sum_y = 0;
    for (auto [y, cnt] : mp_y) {
        sum_y += cnt;
        if (sum_y & 1) {
            T = y;
            break;
        }
    }
    cout << S << ' ' << T - S << '\n';
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