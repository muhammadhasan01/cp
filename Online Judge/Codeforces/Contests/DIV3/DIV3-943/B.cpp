#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, p;
    cin >> s >> p;
    int i = 0;
    for (int j = 0; j < m; j++) {
        if (i < n && s[i] == p[j]) {
            i++;
        }
    }
    cout << i << '\n';
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