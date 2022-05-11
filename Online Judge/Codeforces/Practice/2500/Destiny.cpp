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

int getMin(pvertex v, pvertex w, int s, int e, int need) {
    int res = v->val - w->val;
    if (res < need) {
        return -1;
    }
    if (s == e) {
        return s;
    }
    int mid = (s + e) >> 1;
    int id = getMin(v->l, w->l, s, mid, need);
    if (id != -1) {
        return id;
    }
    return getMin(v->r, w->r, mid + 1, e, need);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> cnt_a(n + 1);
    vector<pvertex> psegtree(n + 1);
    psegtree[0] = build(1, n); 
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        psegtree[i] = update(psegtree[i - 1], 1, n, x, ++cnt_a[x]);
    }
    auto getAnswer = [&](int l, int r, int k) -> int {
        int need = (r - l + 1) / k + 1;
        return getMin(psegtree[r], psegtree[l - 1], 1, n, need);
    };
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << getAnswer(l, r, k) << '\n';
    }
    
    return 0;
}