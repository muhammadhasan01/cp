#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<char> s(n + 1);
    vector<int> pos = {0};
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i] == '1') {
            pos.emplace_back(i);
        }
    }
    if ((int) pos.size() == 1) {
        for (int i = 1; i <= n; i++) {
            cout << 0 << " \n"[i == n];
        }
        return;
    }
    vector<int> suf(n + 2);
    vector<long long> ssuf(n + 2);
    for (int i = n; i >= 0; i--) {
        suf[i] = suf[i + 1] + (s[i] == '1');
        ssuf[i] = ssuf[i + 1] + (s[i] == '1' ? i : 0);
    }
    int len = (int) pos.size();
    vector<long long> ans(n + 1, -1LL);
    for (int i = n - 1, idx = 1; i >= 1; i--, idx++) {
        auto can = [&](int k) -> bool {
            int sz = i - pos[k];
            return sz >= suf[pos[k] + 1];
        };

        int l = 0, r = len - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at != -1) {
            int p = pos[at];
            int num = suf[p + 1];
            int lft = i - num + 1;
            ans[idx] = ssuf[p + 1] - 1LL * lft * num - 1LL * (num - 1) * num / 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}