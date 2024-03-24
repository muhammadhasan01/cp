#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long k, x, a;
    cin >> k >> x >> a;
    long long need = a + 1;
    long long cur = a;
    for (int i = 0; i < x; i++) {
        long long dist = need - cur;
        long long dif = (dist + k - 2) / (k - 1);
        cur -= dif;
        if (cur <= 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << (cur * k >= need ? "YES" : "NO") << '\n';
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