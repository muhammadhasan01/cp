#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const string VIKA = "vika#";

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int pos = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (g[i][j] == VIKA[pos]) {
                pos++;
                break;
            }
        }
    }
    cout << (pos == K ? "YES" : "NO") << '\n';
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