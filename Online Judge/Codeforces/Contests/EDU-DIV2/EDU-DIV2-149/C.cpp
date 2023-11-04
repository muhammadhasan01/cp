#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<bool> vis(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            vis[i] = true;
            q.emplace(i);
        }
    }
    if (q.empty()) {
        cout << string(n, '0') << '\n';
        return;
    }
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        for (int i = pos + 1; i < n; i++) {
            if (vis[i]) {
                break;
            }
            vis[i] = true;
            s[i] = s[pos];
        }
        for (int i = pos - 1; i >= 0; i--) {
            if (vis[i]) {
                break;
            }
            vis[i] =true;
            s[i] = s[pos];
        }
    }
    cout << s << '\n';
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