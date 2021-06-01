#include <bits/stdc++.h>

using namespace std;

const int D = 10;
const int N = (1 << D);

int d, n;
int dp[N];
set<int> children[N + 5];
bool ok[N + 5];
char a[N + 5][D + 5];
vector<char> ans;

void dfs(int num) {
    int maks = 0, pos = -1;
    for (int i = 0; i < d; i++) {
        if (num & (1 << i)) continue;
        int cnum = num | (1 << i);
        if (dp[cnum] > maks) {
            maks = dp[cnum];
            pos = i;
        }
    }
    if (pos == -1) return;
    ans.emplace_back(char(int('0') + pos));
    int new_num = num | (1 << pos);
    if (ok[new_num]) {
        ok[new_num] = false;
        dp[new_num]--;
        for (int x : children[new_num]) dp[x]--;
    }
    dfs(new_num);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int mask = 1; mask < N; mask++) {
        int num = 0;
        vector<int> on;
        for (int i = 0; i < D; i++) {
            int cur = (1 << i);
            if (mask & cur) {
                num |= cur;
                on.emplace_back(cur);
            } 
        }
        for (int x : on) {
            int child = (num ^ x);
            children[num].emplace(child);
            for (int c : children[child]) children[num].emplace(c);
        }
    }

    cin >> d >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = 1; j <= d; j++) {
            if (a[i][j] == '1') {
                num |= (1 << (j - 1));
            }
        }
        ok[num] = true;
        dp[num]++;
        for (int child : children[num]) dp[child]++;
    }
    for (int rep = 0; rep < n; rep++) {
        dfs(0);
        if (dp[0] > 0) ans.emplace_back('R');
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }

    return 0;
}