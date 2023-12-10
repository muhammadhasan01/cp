#include <bits/stdc++.h>

using namespace std;

const int A = 26;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<deque<int>> pos(A);
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        pos[x].emplace_back(i);
    }
    for (int i = 0; i < m; i++) {
        int x = t[i] - 'a';
        if (pos[x].empty()) {
            cout << "NO" << '\n';
            return;
        }
        for (int y = 0; y < x; y++) {
            while (!pos[y].empty() && pos[y].front() < pos[x].front()) {
                pos[y].pop_front();
            }
        }
        pos[x].pop_front();
    }
    cout << "YES" << '\n';
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