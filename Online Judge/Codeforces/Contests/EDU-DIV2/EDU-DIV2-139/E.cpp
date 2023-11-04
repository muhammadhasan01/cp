#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto getNewList = [&](vector<int> lst, int val) {
        vector<int> ret = lst;
        for (int& x : ret) {
            if (x & val) {
                x = val;
                return ret;
            }
        }
        ret.emplace_back(val);
        return ret;
    };

    long long ans = 0;
    map<vector<int>, long long> dp;
    int cntZero = 0;
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        if (val == 0) {
            ans += 1LL * i * (n - i + 1);
            cntZero++;
        } else {
            map<vector<int>, long long> ndp;
            ndp[{val}] += (cntZero + 1);
            cntZero = 0;
            for (auto& [v, cnt] : dp) {
                vector<int> w = getNewList(v, val);
                ndp[w] += cnt;
            }
            swap(dp, ndp);
        }
        for (auto& [v, cnt] : dp) {
            int len = v.size();
            ans += 1LL * len * cnt;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}