#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;
int par[30], sz[30];
vector<int> v[30];
bool vis[30];

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu != pv) {
        if (sz[pu] < sz[pv]) swap(pu, pv);
        sz[pu] += sz[pv];
        par[pv] = pu;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> t;
    for (int i = 0; i < 26; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        int y = t[i] - 'a';
        merge(x, y);
    }

    for (int i = 0; i < 26; i++) {
        int k = fpar(i);
        v[k].push_back(i);
    }

    vector<pair<char,char>> ans;
    for (int i = 0; i < 26; i++) {
        int k = fpar(i);
        int len = v[k].size();
        if (len == 1) continue;
        if (vis[k] == 1) continue;
        vis[k] = 1;
        for (int i = 0; i < len - 1; i++) {
            char x = char(v[k][i] + 'a');
            char y = char(v[k][i + 1] + 'a');
            ans.push_back({x, y});
        }
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first << " " << e.second << '\n';
    }

    return 0;
}
