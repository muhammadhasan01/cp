#include <bits/stdc++.h>

using namespace std;

const int N = 2;

void solve() {
    int m;
    cin >> m;
    vector<vector<long long>> a(N + 1, vector<long long>(2 * m + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = m + 1, k = m; j <= 2 * m; j++, k--) {
            a[i][j] = a[3 - i][k];
        }
    }

    auto getVal = [&](int i, int j) -> pair<long long, int> {
        if (i == 1 && j == 1) {
            return make_pair(a[i][j] - j, j);
        }
        return make_pair(a[i][j] - j + 1, j);
    };

    vector<multiset<pair<long long, int>>> ms(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2 * m; j++) {
            ms[i].emplace(getVal(i, j));
        }
    }
    long long ans = 2 * m + ms[1].rbegin()->first;
    long long now = a[2][1] + 1;
    for (int j = 2; j <= m; j++) {
        for (int i = 1; i <= N; i++) {
            ms[i].erase(ms[i].find(getVal(i, j - 1)));
            ms[i].erase(ms[i].find(getVal(i, 2 * m - j + 2)));
        }
        int turn = (j % 2 == 0 ? 2 : 1);
        now = max(now + 1, a[turn][j] + 1);
        int len = 2 * m - 2 * (j - 1);
        auto [_, posVal] = *ms[turn].rbegin();
        int newPos = posVal - (j - 1);
        long long res = 1LL * len + max(a[turn][posVal] - newPos + 1, now - 1);
        ans = min(ans, res);
        now = max(now + 1, a[3 - turn][j] + 1);
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