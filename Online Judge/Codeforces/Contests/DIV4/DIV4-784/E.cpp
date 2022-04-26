#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> f(K, vector<int>(K));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = s[0] - 'a';
        int y = s[1] - 'a';
        for (int j = 0; j < K; j++) {
            if (j != y) {
                ans += f[x][j];
            }
            if (j != x) {
                ans += f[j][y];
            }
        }
        f[x][y]++;
    }
    cout << ans << '\n';
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