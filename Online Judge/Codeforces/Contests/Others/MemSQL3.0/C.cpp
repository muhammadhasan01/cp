#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int a[N];
bool memo[N][2];
vector<int> dp[N][2];

vector<int> DP(int pos, int turn) {
    if (pos > n) {
        return {0, 0};
    }
    if (memo[pos][turn]) {
        return dp[pos][turn];
    }
    vector<int> ret(2);
    ret[turn] += a[pos];
    vector<int> x = DP(pos + 1, 1 - turn);
    for (int i = 0; i < 2; i++) {
        ret[i] += x[i];
    }
    if (pos + 1 <= n) {
        vector<int> cur(2);
        cur[1 - turn] += a[pos];
        vector<int> y = DP(pos + 1, turn);
        for (int i = 0; i < 2; i++) {
            cur[i] += y[i];
        }
        if (cur[turn] > ret[turn]) {
            ret = cur;
        }
    }
    memo[pos][turn] = true;
    return dp[pos][turn] = ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans = DP(1, 1);
    cout << ans[0] << ' ' << ans[1] << '\n';

    return 0;
}