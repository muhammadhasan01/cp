#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        deque<int> v;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == '.') {
                v.emplace_back(i);
            } else if (a[i][j] == 'o') {
                v.clear();
            } else if (a[i][j] == '*') {
                if (!v.empty()) {
                    int pos = v.front();
                    v.pop_front();
                    a[pos][j] = '*';
                    a[i][j] = '.';
                    v.emplace_back(i);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
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