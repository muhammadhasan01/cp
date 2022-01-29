#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, c = 0; j < m; j++) {
            if (v[i][j] == '>') {
                c++;
            } else if (v[i][j] == '<') {
                ans += c;
            } else {
                c = 0;
                continue;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0, c = 0; i < n; i++) {
            if (v[i][j] == 'v') {
                c++;
            } else if (v[i][j] == '^') {
                ans += c;
            } else {
                c = 0;
                continue;
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}