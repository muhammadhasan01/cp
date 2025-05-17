#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 2;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector r(n, vector<long long>(K));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < K; k++) {
            r[i][k] = rng();
        }
    }
    map<pair<long long, long long>, int> mp;
    int ans = 0;
    pair<int, int> pos = {-1, -1};
    for (int j = 0; j < m; j++) {
        vector<long long> hash(K);
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '1') {
                for (int k = 0; k < K; k++) {
                    hash[k] ^= r[i][k];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            long long h1 = hash[0] ^ r[i][0];
            long long h2 = hash[1] ^ r[i][1];
            int cur = ++mp[{h1, h2}];
            if (cur > ans) {
                ans = cur;
                pos = {i, j};
            }
        }
    }
    auto [x, y] = pos;
    string s(n, '0');
    for (int i = 0; i < n; i++) {
        if (i == x) {
            if (a[i][y] == '0') {
                s[i] = '1';
            }
        } else {
            if (a[i][y] == '1') {
                s[i] = '1';
            }
        }
    }
    cout << ans << '\n';
    cout << s << '\n';
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