#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    if (cnt[0] != cnt[1]) {
        cout << min(cnt[0], cnt[1]) << '\n';
        return;
    }
    cout << cnt[0] - 1 << '\n';
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