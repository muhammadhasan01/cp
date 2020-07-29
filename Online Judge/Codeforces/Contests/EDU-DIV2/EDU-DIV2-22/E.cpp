#include <bits/stdc++.h>

using namespace std;

struct vertex {
    int val;
    vertex *l, *r;
    vertex(int val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(0), l(l), r(r) {
        if (l) val += l->val;
        if (r) val += r->val;
    }
};
typedef vertex* pvertex;

const int N = 1e5;

int n, k, q;
vector<int> v[N + 5];
int cnt[N + 5];
pvertex p[N + 5];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(0);
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
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) return v->val;
    int mid = (s + e) >> 1;
    int p1 = getQuery(v->l, s, mid, l, r);
    int p2 = getQuery(v->r, mid + 1, e, l, r);
    return p1 + p2;
}

int get(int l, int r) {
    return getQuery(p[r], 0, N, 0, l - 1) - getQuery(p[l - 1], 0, N, 0, l - 1);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    p[0] = build(0, N);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[x].emplace_back(i);
        int len = v[x].size();
        int res = (len > k ? v[x][len - k - 1] : 0);
        p[i] = update(p[i - 1], 0, N, res, ++cnt[res]);
    }
    cin >> q;
    int last = 0, l, r;
    while (q--) {
        int x, y;
        cin >> x >> y;
        l = ((x + last) % n) + 1, r = ((y + last) % n) + 1;
        if (l > r) swap(l, r);
        last = get(l, r);
        cout << last << '\n';
    }

    return 0;
}