#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<char> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int depth = n + 5;
    vector<long long> dp(n + 1);
    vector<int> R(n + 1);
    vector<int> idxDepth(n + 1);
    vector<int> cntDepth(depth);
    vector<long long> sumDepth(depth);
    vector<vector<int>> posDepth(depth);
    vector<int> st;
    for (int i = 1, curdepth = 0; i <= n; i++) {
        if (s[i] == '(') {
            st.emplace_back(i);
            curdepth++;
        } else if (s[i] == ')') {
            if (st.empty()) {
                continue;
            }
            int L = st.back();
            st.pop_back();
            curdepth--;
            int cnt = cntDepth[curdepth + 1];
            dp[i] = 1 + 1LL * cnt * (cnt - 1) / 2 + sumDepth[curdepth + 1];
            idxDepth[i] = curdepth;
            R[L] = i;
            cntDepth[curdepth]++;
            sumDepth[curdepth] += dp[i];
            posDepth[curdepth].emplace_back(i);
            cntDepth[curdepth + 1] = 0;
            sumDepth[curdepth + 1] = 0;
        }
    }
    vector<vector<long long>> pref(depth);
    vector<int> idxPref(n + 1);
    for (int d = 0; d < depth; d++) {
        if (posDepth[d].empty()) {
            continue;
        }
        int len = (int) posDepth[d].size();
        pref[d].resize(len);
        for (int i = 0; i < len; i++) {
            int pos = posDepth[d][i];
            pref[d][i] = dp[pos] + (i > 0 ? pref[d][i - 1] : 0);
            idxPref[pos] = i;
        }
    }

    auto answer = [&](int l, int r) -> void {
        int d = idxDepth[r];
        int lft = idxPref[R[l]];
        int rgt = idxPref[r];
        int cnt = rgt - lft + 1;
        long long ans = pref[d][rgt] - (lft > 0 ? pref[d][lft - 1] : 0) + 1LL * cnt * (cnt - 1) / 2;
        cout << ans << '\n';
    };

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            assert(false);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            answer(l, r);
        }
    }
    
    return 0;
}