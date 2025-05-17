#include <bits/stdc++.h>

using namespace std;

const int B = 750;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }
    vector<pair<int, int>> qr(m);
    for (auto& [op, k] : qr) {
        cin >> op >> k;
        --k;
    }

    vector<int> last(n, m);
    vector<int> suff(m);
    for (int i = m - 1; i >= 0; i--) {
        auto [op, k] = qr[i];
        if (op == 1) {
            suff[i] = last[k] - 1;
        } else if (op == 2) {
            last[k] = i;
        }
    }
    vector<int> ans(m);
    vector<int> pref(m + 1);
    vector<int> start(n);
    vector<vector<int>> cnt(B + 1);
    for (int i = 1; i <= B; i++) {
        cnt[i].assign(i, 0);
    }

    auto handleLarge = [&](int op, int k, int i) -> void {
        if (op == 2) {
            return;
        }
        auto [x, y] = p[k];
        int sum = x + y;
        int ed = suff[i];
        for (int l = i + x; l <= ed; l += sum) {
            int r = min(ed, l + y - 1);
            pref[l]++;
            pref[r + 1]--;
        }
    };

    auto handleSmall = [&](int op, int k, int i) -> void {
        if (op == 1) {
            start[k] = i;
        }
        auto [x, y] = p[k];
        int sum = x + y;
        int add = (op == 1 ? 1 : -1);
        for (int j = start[k] + x; j < start[k] + sum; j++) {
            cnt[sum][j % sum] += add;
        }
    };

    auto addFromSmall = [&](int i) -> void {
        for (int b = 1; b <= B; b++) {
            ans[i] += cnt[b][i % b];
        }
    };

    for (int i = 0; i < m; i++) {
        auto [op, k] = qr[i];
        auto [x, y] = p[k];
        if (x + y > B) {
            handleLarge(op, k, i);
        } else {
            handleSmall(op, k, i);
        }
        addFromSmall(i);
    }
    for (int i = 0; i < m; i++) {
        if (i > 0) {
            pref[i] += pref[i - 1];
        }
        ans[i] += pref[i];
        cout << ans[i] << '\n';
    }
    
    return 0;
}