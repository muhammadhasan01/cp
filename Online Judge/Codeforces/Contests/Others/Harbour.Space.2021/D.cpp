#include <bits/stdc++.h>

using namespace std;

const int K = 26;

vector<int> pos[K][2];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 2; j++) {
            pos[i][j].clear();
        }
    }
    for (int i = 0; i < n; i++) {
        int num = s[i] - 'a';
        pos[num][i % 2].emplace_back(i);
    }
    for (int i = 0, cur = -1; i < m; i++) {
        int num = t[i] - 'a';
        int bit = i % 2;
        if (pos[num][bit].empty()) {
            cout << "NO" << '\n';
            return;
        }
        auto it = upper_bound(pos[num][bit].begin(), pos[num][bit].end(), cur);
        if (it == pos[num][bit].end()) {
            cout << "NO" << '\n';
            return;
        }
        cur = *it;
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}