#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    multiset<pair<int, int>> ms;
    for (int i = 1; i <= n; i++) {
        ms.emplace(cnt[i], cnt[i]);
    }

    while (true) {
        auto [rt, rx] = *ms.rbegin();
        auto [lt, lx] = *ms.begin();
        if (rx == 0 || lt + 2 >= rt) {
            break;
        }
        ms.erase(ms.find({rt, rx}));
        ms.erase(ms.find({lt, lx}));
        ms.emplace(rt - 1, rx - 1);
        ms.emplace(lt + 2, lx);
    }
    cout << ms.rbegin()->first << '\n';
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