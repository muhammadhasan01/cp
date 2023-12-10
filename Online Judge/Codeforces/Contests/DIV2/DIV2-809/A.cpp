#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s(m, 'B');
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int l = x - 1;
        int r = m - x;
        if (l > r) {
            swap(l, r);
        }
        if (s[l] == 'B') {
            s[l] = 'A';
        } else {
            s[r] = 'A';
        }
    }
    cout << s << '\n';
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