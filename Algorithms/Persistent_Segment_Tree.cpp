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

const int N = 1e5 + 5;
int n;
int a[N];
pvertex psegtree[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(a[s]);
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