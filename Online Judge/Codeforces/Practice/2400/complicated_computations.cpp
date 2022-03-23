#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

struct vertex {
    int val;
    vertex *l, *r;
    vertex(int val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(INF), l(l), r(r) {
        if (l) val = min(val, l->val);
        if (r) val = min(val, r->val);
    }
};
typedef vertex* pvertex;

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(-1);
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos, int val) {
    if (s == e && s == pos)
        return new vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos, val));
}

int getQuery(pvertex v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return INF;
    if (l <= s && e <= r) return v->val;
    int mid = (s + e) >> 1;
    int p1 = getQuery(v->l, s, mid, l, r);
    int p2 = getQuery(v->r, mid + 1, e, l, r);
    return min(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 2);
    int m = 2 * n;
    vector<vector<int>> pos(m + 1);
    for (int i = 0; i <= m; i++) {
        pos[i].emplace_back(0);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].emplace_back(i);
    }
    for (int i = 0; i <= 2 * n; i++) {
        pos[i].emplace_back(n + 1);
    }
    vector<pvertex> psegtree(n + 2);
    psegtree[0] = build(0, m);
    for (int i = 1; i <= n; i++) {
        psegtree[i] = update(psegtree[i - 1], 0, m, a[i], i);
    }
    psegtree[n + 1] = update(psegtree[n], 0, m, 0, -1);
    // check for ans == 1 and ans == 2
    int cnt_one = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cnt_one++;
        }
    }
    if (cnt_one == 0) {
        cout << 2 << '\n';
        return 0;
    }
    if (cnt_one == n) {
        cout << 1 << '\n';
        return 0;
    }
    // check every answer
    for (int c = 3; c <= 2 * n; c++) {
        int len = pos[c].size();
        bool ok = false;
        for (int i = 1; i < len; i++) {
            int l = pos[c][i - 1];
            int r = pos[c][i];
            int lft = getQuery(psegtree[r], 0, m, 1, c - 1);
            if (lft > l) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << c << '\n';
            return 0;
        }
    }

    return 0;
}