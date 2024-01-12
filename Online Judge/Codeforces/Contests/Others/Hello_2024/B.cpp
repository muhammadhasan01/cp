#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(K);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        if (cc == '+') {
            cnt[0]++;
        } else {
            cnt[1]++;
        }
    }
    int mx = max(cnt[0], cnt[1]);
    int mn = min(cnt[0], cnt[1]);
    cout << mx - mn << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}