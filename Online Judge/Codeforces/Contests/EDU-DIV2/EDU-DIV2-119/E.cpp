#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            v[i] = make_pair(x, -1);
        } else {
            int x, y;
            cin >> x >> y;
            v[i] = make_pair(x, y);
        }
    }
    vector<int> dp(n);
    vector<int> last(N, -1);
    for (int i = n - 1; i >= 0; i--) {
        auto [x, y] = v[i];
        if (y == -1) {
            continue;
        }
        if (last[y] != -1) {
            dp[i] = dp[last[y]];
        } else {
            dp[i] = y;
        }
        last[x] = i;
    }
    deque<int> ans;
    fill(last.begin(), last.end(), -1);
    for (int i = n - 1; i >= 0; i--) {
        auto [x, y] = v[i];
        if (y == -1) {
            int val = (last[x] == -1 ? x : dp[last[x]]);
            ans.emplace_front(val);
        } else {
            last[x] = i;
        }
    }
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }

    return 0;
}