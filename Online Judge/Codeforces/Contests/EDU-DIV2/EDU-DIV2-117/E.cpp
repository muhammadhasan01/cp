#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 20;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<bool> exists(N);
    vector<vector<int>> cnt(N, vector<int>(K + 1));
    for (int i = 0; i < n; i++) {
        int m, k;
        cin >> m >> k;
        exists[m] = true;
        cnt[m][k]++;
    }
    vector<int> vals;
    for (int i = 0; i < N; i++) {
        if (!exists[i]) {
            continue;
        }
        vals.emplace_back(i);
    }

    auto getMessages = [&](int len) -> vector<pair<long long, int>> {
        vector<pair<long long, int>> res;
        for (int val : vals) {
            long long cur = 0;
            for (int k = 1; k <= K; k++) {
                if (k < len) {
                    cur += 1LL * cnt[val][k] * k;
                } else {
                    cur += 1LL * cnt[val][k] * len;
                }
            }
            res.emplace_back(cur, val);
        }
        sort(res.rbegin(), res.rend());
        return res;
    };

    int len = 1;
    vector<pair<long long, int>> messages;
    pair<long long, long long> best = make_pair(-1L, 1L);
    long long sum = 0;
    for (int l = 1; l <= min((int) vals.size(), K); l++) {
        if (l <= K + 1) {
            messages = getMessages(l);
            sum = 0;
            for (int i = 0; i < l; i++) {
                sum += messages[i].first;
            }
        } else {
            sum += messages[l - 1].first;
        }
        if (1LL * sum * best.second > 1LL * l * best.first) {
            best = make_pair(sum, l);
            len = l;
        }
    }
    vector<pair<long long, int>> ans = getMessages(len);
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i].second << " \n"[i == len - 1];
    }
    
    return 0;
}
