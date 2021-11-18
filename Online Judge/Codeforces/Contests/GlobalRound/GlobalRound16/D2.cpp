#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int len = n * m;
    vector<int> a(len + 1);
    for (int i = 1; i <= len; i++) {
        cin >> a[i];
    }
    // compress
    {
        map<int, int> mp;
        vector<int> b = a;
        sort(b.begin() + 1, b.end());
        int cnt = 0;
        for (int i = 1; i <= len; i++) {
            if (mp.count(b[i]) == 0) {
                mp[b[i]] = ++cnt;
            }
        }
        for (int i = 1; i <= len; i++) {
            a[i] = mp[a[i]];
        }
    }
    vector<vector<int>> pos(len + 1);
    for (int i = 1; i <= len; i++) {
        pos[a[i]].emplace_back(i);
    }
    sort(a.begin() + 1, a.end());
    long long ans = 0;
    for (int i = len; i >= 1; i -= m) {
        int j = i - m + 1;
        vector<int> bit(len + 1);
        auto add = [&](int x, int val) {
            for ( ; x <= len; x += x & -x) {
                bit[x] += val;
            }
        };
        auto get = [&](int x) -> long long {
            long long ret = 0;
            for ( ; x > 0; x -= x & -x) {
                ret += bit[x];
            }
            return ret;
        };
        for (int it = j; it <= i; it++) {
            int num = pos[a[it]].back();
            pos[a[it]].pop_back();
            ans += get(num - 1);
            add(num, 1);
        }
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