#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> P(N + 1), W(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> P[i];
    }
    int K;
    cin >> K;
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1));
    vector<vector<pair<int, int>>> go(N + 1, vector<pair<int, int>>(K + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            go[i][j] = make_pair(i - 1, j);
            if (j >= W[i] && dp[i - 1][j - W[i]] + P[i] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - W[i]] + P[i];
                go[i][j] = make_pair(i - 1, j - W[i]);
            }
        }
    }
    vector<int> ans;
    int tot_weight = 0;
    int i = N, j = K;
    while (i > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            ans.emplace_back(i);
            tot_weight += W[i];
            int bi = go[i][j].first;
            int bj = go[i][j].second;
            i = bi, j = bj;
        }
    }
    reverse(ans.begin(), ans.end());
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
    cout << '\n';
    cout << tot_weight << '\n';
    cout << '\n';
    cout << dp[N][K] << '\n';

    return 0;
}