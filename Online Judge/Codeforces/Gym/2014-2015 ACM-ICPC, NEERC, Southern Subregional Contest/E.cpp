// author: mhasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int m[N], r[N];
int dp[N], go[N];
bool c[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int winStation = 0;
    for (int i = 1; i <= n; i++) {
        cin >> m[i] >> r[i];
        if (m[i] > r[i]) {
            winStation++;
            c[i] = true;
        }
    }
    if (winStation > n / 2) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        go[i] = i - 1;
        bool trans = false;
        if (!c[i] && !c[i - 1]) trans = true;
        if (!c[i] && m[i - 1] + m[i] > r[i - 1] + r[i]) trans = true;
        if (c[i] && !c[i - 1] && m[i - 1] + m[i] > r[i - 1] + r[i]) trans = true;
        if (trans && 1 + dp[i - 2] > dp[i]) {
            dp[i] = 1 + dp[i - 2];
            go[i] = i - 2;
        }
        if (winStation > (n - dp[i]) / 2) {
            vector<pair<int, int>> ans;
            int cur = i;
            while (cur > 0) {
                int j = go[cur];
                if (j == cur - 2) {
                    ans.push_back({cur - 1, cur});
                }
                cur = j;
            }
            cout << ans.size() << "\n";
            for (auto& e : ans) {
                cout << e.first << " " << e.second << '\n';
            }
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}