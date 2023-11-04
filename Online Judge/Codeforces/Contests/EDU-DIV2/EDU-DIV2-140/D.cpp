#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        char cc;
        cin >> cc;
        if (cc == '1') {
            x += (1 << j);
            j++;
        } else if (cc == '0') {
            y += (1 << k);
            k++;
        }
    }
    int l = x + 1;
    int r = (1 << n) - y;
    for (int i = l; i <= r; i++) {
        cout << i << " \n"[i == r];
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