#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    int len = -1;
    long long res = 0;
    long long cur = 9;
    for (int val = 1; ;val++) {
        res += cur;
        if (res >= n) {
            res -= cur;
            len = val;
            break;
        }
        cur *= 10;
    }
    long long add = 1;
    for (int i = 0; i < len - 1; i++) {
        add = (add * 10);
    }
    vector<int> ans;
    for (int i = 0; i < len; i++) {
        for (int j = (i == 0 ? 1 : 0); j <= 9; j++) {
            res += add;
            if (res >= n) {
                ans.emplace_back(j);
                res -= add;
                add /= 10;
                break;
            }
        }
    }
    int sz = ans.size();
    for (int i = 0; i < sz; i++) {
        cout << ans[i];
    }
    for (int i = sz - 2; i >= 0; i--) {
        cout << ans[i];
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case " << T << ": ";
        solve();
    }

    return 0;
}