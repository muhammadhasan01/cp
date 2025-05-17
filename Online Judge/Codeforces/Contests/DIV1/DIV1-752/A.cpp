#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    bool good = true;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bool nice = false;
        for (int j = i + 1; j >= 2; j--) {
            if (x % j != 0) {
                nice = true;
                break;
            }
        }
        if (!nice) {
            good = false;
        }
    }
    cout << (good ? "YES" : "NO") << '\n';
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