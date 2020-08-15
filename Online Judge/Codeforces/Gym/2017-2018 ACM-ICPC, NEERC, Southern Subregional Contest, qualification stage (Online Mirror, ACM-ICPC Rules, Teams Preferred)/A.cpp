#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n;
int par[N];
int l[N], r[N];
pair<int, int> p[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] > 0) merge(l[i], i);
        if (r[i] > 0) merge(r[i], i);
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        int parent = fpar(i);
        if (l[i] == 0) p[parent].first = i;
        if (r[i] == 0) p[parent].second = i;
        if (parent == i) v.emplace_back(i);
    }
    int len = v.size();
    for (int i = 1; i < len; i++) {
        r[p[v[i - 1]].second] = p[v[i]].first; 
        l[p[v[i]].first] = p[v[i - 1]].second;
    }
    for (int i = 1; i <= n; i++) {
        cout << l[i] << " " << r[i] << "\n";
    }

    return 0;
}