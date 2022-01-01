#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> l(3);
    for (int i = 0; i < 3; i++) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    if (l[0] + l[1] == l[2]) {
        cout << "YES" << '\n';
        return;
    }
    if (l[1] == l[2] && l[0] % 2 == 0) {
        cout << "YES" << '\n';
        return;
    }
    if (l[0] == l[1] && l[2] % 2 == 0) {
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
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