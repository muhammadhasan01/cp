#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    map<int, set<vector<pair<int, int>>>> mp;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        vector<pair<int, int>> v;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 'O') {
                res = -1;
                break;
            }
            if (a[i][j] != 'X') {
                v.emplace_back(i, j);
                res++;
            }
        }
        if (res == -1) {
            continue;
        }
        sort(v.begin(), v.end());
        mp[res].emplace(v);
    }
    for (int j = 1; j <= n; j++) {
        int res = 0;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 'O') {
                res = -1;
                break;
            }
            if (a[i][j] != 'X') {
                v.emplace_back(i, j);
                res++;
            }
        }
        if (res == -1) {
            continue;
        }
        sort(v.begin(), v.end());
        mp[res].emplace(v);
    }
    if (mp.empty()) {
        cout << "Impossible" << '\n';
        return;
    }
    auto it = mp.begin();
    cout << it->first << ' ' << it->second.size() << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}