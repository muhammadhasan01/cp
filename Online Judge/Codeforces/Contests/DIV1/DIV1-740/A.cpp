#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    int n = a + b;
    vector<int> ans;
    for (int x : {n / 2, (n + 1) / 2}) {
        int rem = x - a;
        for (int i = rem, j = a; i <= n && j >= 0; i += 2, j--) {
            ans.emplace_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    int len = ans.size();
    cout << len << '\n';
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
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}