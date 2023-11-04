#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    auto getSum = [&](int x) -> long long {
        return 1LL * x * (x + 1) / 2;
    };

    int l = pos[0], r = pos[0];
    long long ans = 0;
    for (int mex = 1; mex < n; mex++) {
        int len = r - l + 1;
        int maxLen = 2 * mex;
        int i = pos[mex];
        if (len <= maxLen) {
            int dif = maxLen - len;
            if (i < l || i > r) {
                // L -> mostleft index we can extend
                // R -> mostright index we can extend
                int L = max(i < l ? i + 1 : 0, l - dif);
                int R = min(i > r ? i - 1 : n - 1, r + dif);
                int cntL = l - L;
                int cntR = R - r;
                ans += (cntL + cntR + 1);
                int x = min(cntL, cntR);
                int y = max(cntL, cntR);
                // count how many times we use the maxLen
                int cnt = min(x, dif - y);
                ans += 1LL * y * cnt;
                x -= cnt;
                ans += getSum(y - 1) - getSum(y - x - 1);
            }
        }
        while (i < l) {
            l--;
        }
        while (i > r) {
            r++;
        }
    }
    cout << ans + 1 << '\n';
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