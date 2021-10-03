#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int nprime[N];

void solve() {
    int n;
    cin >> n;
    map<vector<int>, int> mp;
    auto handle_val = [&](int x) -> void {
        vector<int> v;
        while (x > 1) {
            int p = nprime[x];
            int c = 0;
            while (x % p == 0) {
                x /= p;
                c ^= 1;
            }
            if (c) {
                v.emplace_back(p);
            }
        }
        mp[v]++;
    };
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        handle_val(x);
    }
    vector<int> ans(2);
    int cnt_sqr = 0;
    for (auto& [v, c] : mp) {
        ans[0] = max(ans[0], c);
        if (c % 2 == 0) {
            cnt_sqr += c;
        } else {
            ans[1] = max(ans[1], c);
            if (v.empty()) {
                cnt_sqr += c;
            }
        }
    }
    ans[1] = max(ans[1], cnt_sqr);
    int q;
    cin >> q;
    while (q--) {
        long long w;
        cin >> w;
        if (w > 0) {
            cout << ans[1] << '\n';
        } else {
            cout << ans[0] << '\n';
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 2; i < N; i++) {
        if (nprime[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            nprime[j] = i;
        }
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}