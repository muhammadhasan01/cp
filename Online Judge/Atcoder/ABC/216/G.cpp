#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> in(n + 1), out(n + 1);
    vector<int> avail(m);
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        in[l].emplace_back(i);
        out[r].emplace_back(i);
        avail[i] = (r - l + 1) - x;
    }
    vector<int> ans(n + 1, 1);
    vector<int> valrem(m + 1);
    multiset<int> ms;
    int add = 0;
    for (int x = 1; x <= n; x++) {
        for (int i : in[x]) {
            valrem[i] = avail[i] + add;
            ms.emplace(valrem[i]);
        }
        if (ms.empty()) {
            ans[x] = 0;
        } else if (*ms.begin() >= add + 1) {
            add++;
            ans[x] = 0;
        }
        for (int i : out[x]) {
            auto it = ms.find(valrem[i]);
            if (it != ms.end()) {
                ms.erase(it);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    
    return 0;
}