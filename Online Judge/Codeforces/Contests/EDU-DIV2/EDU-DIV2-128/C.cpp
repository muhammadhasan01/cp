#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<array<int, 2>> pre(n + 2);
    vector<array<int, 2>> suf(n + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        int num = s[i - 1] - '0';
        pre[i][num]++;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 2; j++) {
            suf[i][j] = suf[i + 1][j];
        }
        int num = s[i - 1] - '0';
        suf[i][num]++;
    }

    auto can = [&](int val) -> bool {
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') {
                continue;
            }
            int cur = suf[i + 1][1];
            if (cur > val) {
                continue;
            }
            int need = val - cur;
            int l = 1, r = i, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[mid - 1][1] <= need) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at == -1) {
                continue;
            }
            int zero = pre[i][0] - pre[at - 1][0];
            if (zero <= val) {
                return true;
            }
        }
        return false;
    };

    int l = 0, r = n, ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << min(ans, pre[n][1]) << '\n';
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