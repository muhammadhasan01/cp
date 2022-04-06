#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int TARGET = 1e6;

void solve() {
    vector<int> val(4, INF);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            val[j] = min(val[j], x);
        }
    }
    int need = TARGET;
    vector<int> ans(4);
    for (int i = 0; i < 4; i++) {
        int cur = min(val[i], need);
        need -= cur;
        ans[i] = cur;
    }
    if (need > 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 0; i < 4; i++) {
        cout << ans[i] << " \n"[i == 3];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}