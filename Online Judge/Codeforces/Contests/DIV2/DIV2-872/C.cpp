#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> st;
    int L = 0, R = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            L++;
        } else if (x == -2) {
            R++;
        } else if (x > 0) {
            st.emplace(x);
        }
    }

    auto solveByL = [&](int l) -> int {
        int ret = 0;
        for (int i = m; i >= 1; i--) {
            if (st.count(i)) {
                ++ret;
                continue;
            }
            if (l > 0) {
                ++ret;
                --l;
            }
        }
        return ret;
    };

    auto solveByR = [&](int r) -> int {
        int ret = 0;
        for (int i = 1; i <= m; i++) {
            if (st.count(i)) {
                ++ret;
                continue;
            }
            if (r > 0) {
                ++ret;
                --r;
            }
        }
        return ret;
    };

    auto solveByLAndR = [&](int l, int r) -> int {
        if (st.empty()) {
            return min(m, max(l, r));
        }

        vector<int> a(st.begin(), st.end());
        int len = a.size();
        vector<int> pre(len);
        pre[0] = a[0] - 1;
        for (int i = 1; i < len; i++) {
            pre[i] = pre[i - 1] + (a[i] - a[i - 1] - 1);
        }
        vector<int> suf(len);
        suf[len - 1] = m - a[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + (a[i + 1] - a[i] - 1);
        }
        int ret = 0;
        for (int i = 0; i < len; i++) {
            int cur = len + min(pre[i], l) + min(suf[i], r);
            ret = max(ret, cur);
        }
        return ret;
    };

    cout << max({solveByL(L), solveByR(R), solveByLAndR(L, R)}) << '\n';
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