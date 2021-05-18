#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
int a[N][N];
int ans[N + N];
vector<pair<int, int>> edges;

int calc(vector<int> lst) {
    if ((int) lst.size() == 1)
        return lst[0];
    int maks = -1;
    for (int u : lst)
        maks = max(maks, a[lst[0]][u]);
    vector<vector<int>> sep = {{ lst[0] }};
    for (int i = 1; i < (int) lst.size(); i++) {
        int v = lst[i];
        int pos = -1;
        for (int j = 0; j < (int) sep.size(); j++) {
            if (a[sep[j][0]][v] != maks) {
                pos = j;
                break;
            }
        }
        if (pos == -1) {
            pos = sep.size();
            sep.emplace_back(vector<int>());
        }
        sep[pos].emplace_back(v);
    }
    int v = ++n;
    ans[v] = maks;
    for (auto& e : sep) {
        int u = calc(e);
        edges.emplace_back(u, v);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        ans[i] = a[i][i];
    vector<int> lst(n);
    iota(lst.begin(), lst.end(), 1);
    int root = calc(lst);
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    cout << root << '\n';
    for (auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}