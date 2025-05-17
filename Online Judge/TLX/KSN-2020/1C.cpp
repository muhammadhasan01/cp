#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> H(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> H[i];
    }

    // If you can remove everyone, answer is 0 groups.
    if (k >= n) {
        cout << 0 << "\n";
        return 0;
    }

    // For each health‐value v, store all positions where H[i] == v.
    vector<vector<int>> pos(n+1);
    // last[i] = the index of the “(m+1)th” same‐health person
    // if you tried to include i in a group that already had m of H[i].
    vector<int> last(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        int v = H[i];
        pos[v].push_back(i);
        if ((int)pos[v].size() > m) {
            last[i] = pos[v][pos[v].size() - m - 1];
        }
    }

    const int INF = 1e9;
    // dp[i][j] = { minimum groups used so far, start index of current group }
    static pair<int,int> dp[50001][401];

    // initialize all states to “impossible”
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j].first = INF;
            dp[i][j].second = -INF;
        }
    }
    // before anyone arrives, we have 1 empty group ready at position 1
    dp[0][0] = make_pair(1, 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            // 1) Keep i in the current group, if that group started after last[i]
            if (dp[i-1][j].second > last[i]) {
                dp[i][j] = dp[i-1][j];
            }

            // 2) Remove i (use up one removal)
            if (j > 0) {
                auto cand = dp[i-1][j-1];
                if (cand.first < dp[i][j].first ||
                   (cand.first == dp[i][j].first && cand.second > dp[i][j].second)) {
                    dp[i][j] = cand;
                }
            }

            // 3) Start a brand‑new group at i
            auto prev = dp[i-1][j];
            pair<int,int> startNew = make_pair(prev.first + 1, i);
            if (startNew.first < dp[i][j].first ||
               (startNew.first == dp[i][j].first && startNew.second > dp[i][j].second)) {
                dp[i][j] = startNew;
            }
        }
    }

    // Answer = min groups after n people with up to k removals
    cout << dp[n][k].first << "\n";
    return 0;
}
