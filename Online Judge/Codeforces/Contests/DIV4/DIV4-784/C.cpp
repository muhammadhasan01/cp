#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (abs(a[i] - a[0]) % 2 != 0) {
                flag = false;
                break;
            }
        } else {
            if (abs(a[i] - a[1]) % 2 != 0) {
                flag = false;
                break;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << '\n';
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