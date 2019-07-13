#include <bits/stdc++.h>
// Finding Euclidean Path
// from user https://codeforces.com/profile/yassin_
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> bp(n - 1), cp(n - 1);
    set<int> s;
    for (int i = 0; i < n - 1; ++i) {
        cin >> bp[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> cp[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        if (bp[i] > cp[i]) {
            cout << -1 << "\n";
            return 0;
        }
        s.insert(bp[i]);
        s.insert(cp[i]);
    }
    map<int, int> id;
    vector<int> inv;
    int cur = 0;
    for (int x : s) {
        inv.push_back(x);
        id[x] = cur++;
    }
    vector<multiset<int>> g(cur);
    for (int i = 0; i < n - 1; ++i) {
        int u = id[bp[i]], v = id[cp[i]];
        g[u].insert(v);
        g[v].insert(u);
    }
    int cur_v = 0, cnt_odd = 0;
    for (int u = 0; u < cur; ++u) {
        if ((int)g[u].size() % 2 == 1) {
            cur_v = u;
            ++cnt_odd;
        }
    }
    if (cnt_odd != 0 && cnt_odd != 2) {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> eul_path;
    stack<int> cur_path;
    cur_path.push(cur_v);
    while (!cur_path.empty()) {
        if (!g[cur_v].empty()) {
            cur_path.push(cur_v);
            int nxt_v = *g[cur_v].begin();
            g[cur_v].erase(g[cur_v].begin());
            g[nxt_v].erase(g[nxt_v].find(cur_v));
            cur_v = nxt_v;
        } else {
            eul_path.push_back(cur_v);
            cur_v = cur_path.top();
            cur_path.pop();
        }
    }
    if ((int)eul_path.size() < n) {
        cout << -1 << "\n";
        return 0;
    }
    for (int u : eul_path) {
        cout << inv[u] << " ";
    }
    cout << "\n";

    return 0;
}.
