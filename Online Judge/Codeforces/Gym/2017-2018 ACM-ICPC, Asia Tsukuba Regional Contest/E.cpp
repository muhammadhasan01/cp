#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    deque<pair<int, int>> dbl, dwh;
    int white = 0, black = 0;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if (b[i] != b[i - 1]) {
            if (b[i] == 'W') {
                white++;
            } else {
                black++;
            }
        }
        if (a[i] == b[i]) {
            ans[i] = ans[i - 1];
            continue;
        }
        int bl = ans[i - 1] + 1 - black + (b[i] == 'B');
        while (!dbl.empty() && dbl.back().first >= bl) {
            dbl.pop_back();
        }
        dbl.emplace_back(bl, i - 1);
        int wh = ans[i - 1] + 1 - white + (b[i] == 'W');
        while (!dwh.empty() && dwh.back().first >= wh) {
            dwh.pop_back();
        }
        dwh.emplace_back(wh, i - 1);
        while (dbl.front().second + k < i) {
            dbl.pop_front();
        }
        while (dwh.front().second + k < i) {
            dwh.pop_front();
        }
        ans[i] = min(white + dwh.front().first, black + dbl.front().first);
    }
    cout << ans[n] << '\n';
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