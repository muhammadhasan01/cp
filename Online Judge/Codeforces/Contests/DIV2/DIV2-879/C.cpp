#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> need(2);
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        need[0] += (s[i] != t[i]);
        need[1] += (s[i] != t[j]);
    }
    int cur = 1;
    int have = 0;
    for (int op = 0; op <= 4 * n; op++) {
        if (op % 2 == 0) {
            cur ^= 1;   
        } else {
            have++;
        }
        if (need[cur] <= have) {
            cout << op << '\n';
            return;
        }
    }
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