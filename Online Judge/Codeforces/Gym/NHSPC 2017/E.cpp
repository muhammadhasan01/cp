#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(N);
    bool exist_duplicate = false;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += (i - cnt[x]);
        if (++cnt[x] > 1) {
            exist_duplicate = true;
        }
    }
    if (exist_duplicate) {
        ++ans;
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