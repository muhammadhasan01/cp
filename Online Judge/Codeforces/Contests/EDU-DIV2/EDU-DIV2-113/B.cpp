#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> twos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            twos.emplace_back(i);
        }
    }
    int len = twos.size();
    if (len == 1 || len == 2) {
        cout << "NO" << '\n';
        return;
    }
    vector<vector<char>> ans(n, vector<char>(n, '='));
    for (int i = 0; i < len; i++) {
        int j = (i + 1) % len;
        ans[twos[i]][twos[j]] = '+';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                ans[i][j] = 'X';
                continue;
            }
            if (ans[i][j] == '+' || ans[j][i] == '+') {
                if (ans[j][i] == '+') {
                    ans[i][j] = '-';
                } else if (ans[i][j] == '+') {
                    ans[j][i] = '-';
                }
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
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