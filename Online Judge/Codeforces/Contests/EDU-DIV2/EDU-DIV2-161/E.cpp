#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int K = 60;

void solve() {
    long long x;
    cin >> x;
    vector<int> ans;
    int up = INF;
    int down = -INF;
    while (x > 0) {
        if (x == 2) {
            ans.emplace_back(0);
            break;
        }
        if (x & 1LL) {
            ans.emplace_back(up--);
            --x;
        } else {
            ans.emplace_back(down++);
            x /= 2;
        }
    }
    int len = (int) ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
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