#include <bits/stdc++.h>

using namespace std;


void solve3(int n) {
    if (n % 2 == 1) {
        int m = n / 2;
        cout << 1 << " " << m << " " << m << '\n';
        return;
    }
    int m = n / 2;
    if (m % 2 == 0) {
        cout << m / 2 << " " << m / 2 << " " << m << '\n';
        return;
    }
    cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << '\n';
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 3) {
        solve3(n);
        return;
    }
    if (n - k <= 2) {
        for (int i = 0; i < k; i++) {
            int res = 1;
            if (i == k - 1) {
                res = n;
            }
            n -= res;
            cout << res << " \n"[i == k - 1];
        }
        return;
    }
    if (n - k == 3) {
        for (int i = 0; i < k; i++) {
            int res = 1;
            if (i >= k - 3) {
                res = 2;
            }
            n -= res;
            cout << res << " \n"[i == k - 1];
        }
        return;
    }
    for (int i = 0; i < k - 3; i++) {
        cout << 1 << " ";
    }
    solve3(n - (k - 3));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}