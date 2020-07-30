#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v[15];
    int ans = n;
    for (int i = 0; i < n; i++) {
        v[(int) (s[i] - '0')].emplace_back(i);
    }
    for (int i = 0; i < 10; i++) {
        int len_1 = v[i].size();
        ans = min(ans, n - len_1);
        if (len_1 == 0) continue;
        for (int j = 0; j < 10; j++) {
            if (i == j) continue;
            int len_2 = v[j].size();
            if (len_2 == 0) continue;
            int cnt = 0;
            int x = 0, y = 0;
            while (x < len_1 && y < len_2) {
                while (y < len_2 && v[j][y] < v[i][x]) ++y;
                if (y == len_2) break;
                ++cnt;
                while (x < len_1 && v[i][x] < v[j][y]) ++x;
            }
            ans = min(ans, n - 2 * cnt);
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}