#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 3;

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 'a') {
            if (a[i] != 'b' && a[i] != 'c') {
                cout << 2 << '\n';
                return;
            }
        }
        if (a[i] == 'a') {
            if (a[i - 1] != 'b' && a[i - 1] != 'c') {
                cout << 2 << '\n';
                return;
            }
        }
    }
    vector<vector<int>> pre(n, vector<int>(K));
    for (int i = 0; i < n; i++) {
        int num = a[i] - 'a';
        pre[i][num]++;
        if (i == 0) {
            continue;
        }
        for (int j = 0; j < K; j++) {
            pre[i][j] += pre[i - 1][j];
        }
    }
    auto get_range = [&](int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        return pre[r][k] - (l == 0 ? 0 : pre[l - 1][k]);
    };
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'a') {
            pos.emplace_back(i);
        }
    }
    int ans = INF;
    int len = pos.size();
    for (int i = 1; i < len; i++) {
        for (int x = 1; x <= 2; x++) {
            if (i - x < 0) {
                continue;
            }
            int l = pos[i - x];
            int r = pos[i];
            vector<int> cnt(K);
            for (int j = 0; j < K; j++) {
                cnt[j] = get_range(l, r, j);
            }
            if (cnt[0] <= cnt[1] || cnt[0] <= cnt[2]) {
                continue;
            }
            ans = min(ans, r - l + 1);
        }
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}