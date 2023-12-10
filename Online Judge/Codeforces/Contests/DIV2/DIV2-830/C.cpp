#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> S(n + 1);
    vector<long long> X(n + 1);
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + a[i];
        X[i] = (X[i - 1] ^ a[i]);
    }
    vector<int> nxt(n + 1);
    for (int i = n; i >= 1; i--) {
        nxt[i] = i + 1;
        if (i + 1 <= n && a[i + 1] == 0) {
            nxt[i] = nxt[i + 1];
        }
    }

    auto getVal = [&](int l, int r) -> long long {
        return (S[r] - S[l - 1]) - (X[r] ^ X[l - 1]);  
    };

    while (q--) {
        int lft, rgt;
        cin >> lft >> rgt;
        tuple<int, int, int> ans = {rgt - lft + 1, lft, rgt};
        long long val = getVal(lft, rgt);
        for (int L = lft; L <= rgt; L = nxt[L]) {
            if (getVal(L, rgt) != val) {
                break;
            }
            int l = L, r = rgt, at = rgt;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (getVal(L, mid) == val) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = min(ans, make_tuple(at - L + 1, L, at));
        }
        cout << get<1>(ans) << ' ' << get<2>(ans) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}
