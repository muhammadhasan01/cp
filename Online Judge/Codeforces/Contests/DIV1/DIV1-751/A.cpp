#include <bits/stdc++.h>

using namespace std;

const int K = 31;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(K);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < K; j++) {
            bool b = x & (1 << j);
            if (b) {
                cnt[j]++;
            }
        }
    }
    int g = 0;
    for (int j = 0; j < K; j++) {
        if (cnt[j] == 0) {
            continue;
        }
        g = __gcd(g, cnt[j]);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (g % i == 0) {
            ans.emplace_back(i);
        }
    }
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
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