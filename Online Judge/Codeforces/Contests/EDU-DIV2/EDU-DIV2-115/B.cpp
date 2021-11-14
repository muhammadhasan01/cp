#include <bits/stdc++.h>

using namespace std;

const int K = 5;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(K + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            cin >> a[i][j];
        }
    }
    if (n % 2 == 1) {
        cout << "NO" << '\n';
        return;
    }
    int m = n / 2;
    for (int x = 1; x <= K; x++) {
        for (int y = 1; y <= K; y++) {
            if (x == y) {
                continue;
            }
            vector<int> xs, ys;
            for (int i = 1; i <= n; i++) {
                if (a[i][x] == 1) {
                    xs.emplace_back(i);
                } else if (a[i][y] == 1) {
                    ys.emplace_back(i);
                }
            }
            int lx = (int) xs.size();
            int ly = (int) ys.size();
            if (lx < m) {
                continue;
            }
            int max_take = lx - m;
            int cnt = 0;
            for (int id : xs) {
                if (a[id][y] == 1 && max_take > 0) {
                    max_take--;
                    cnt++;
                }
            }
            if (ly + cnt >= m) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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