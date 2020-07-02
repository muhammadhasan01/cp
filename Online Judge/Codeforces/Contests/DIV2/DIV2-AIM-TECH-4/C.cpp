#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int par[N];
bool vis[N];
pair<int, int> a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        par[i] = a[i].second;
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cur = i;
        vector<int> res;
        while (!vis[cur]) {
            vis[cur] = 1;
            res.emplace_back(cur);
            cur = par[cur];
        }
        ans.emplace_back(res);
    }
    cout << ans.size() << '\n';
    for (auto& e : ans) {
        cout << e.size() << " ";
        for (auto& el : e) {
            cout << el << " ";
        }
        cout << '\n';
    }

    return 0;
}