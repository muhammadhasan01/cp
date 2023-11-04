#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> mp;
    for (int i = 0; i + 1 < n; i++) {
        string cur = s.substr(i, 2);
        if (mp.count(cur)) {
            int j = mp[cur];
            if (i - j > 1) {
                cout << "YES" << '\n';
                return;
            }
        } else {
            mp[cur] = i;
        }
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