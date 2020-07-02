#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
int a[N];
vector<int> bit;

void add(int x) {
    for ( ; x <= n; x += x & -x) {
        bit[x]++;
    }
}

int get(int x) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        bit.assign(n + 5, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<bool> vis(n + 5);
        vector<bool> pre(n + 5);
        for (int i = 1; i <= n; i++) {
            if (!vis[a[i]]) add(a[i]);
            vis[a[i]] = 1;
            if (get(i) == i) pre[i] = 1;
        }
        bit.assign(n + 5, 0);
        vis.assign(n + 5, 0);
        vector<bool> suf(n + 5);
        for (int i = n; i >= 1; i--) {
            if (!vis[a[i]]) add(a[i]);
            vis[a[i]] = 1;
            if (get(n - i + 1) == n - i + 1) suf[i] = 1;
        }
        vector<pair<int, int>> ans;
        for (int i = 1; i < n; i++) {
            if (pre[i] && suf[i + 1]) {
                ans.push_back({i, n - i});
            }
        }
        cout << ans.size() << '\n';
        for (auto& e : ans) {
            cout << e.first << " " << e.second << '\n';
        }
    }

    return 0;
}