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

const int N = 1e5 + 5;
int n, m;
int a[N], id[N];
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

int query(int s, int e, int k, pvertex L, pvertex R) {
    if (s == e) return id[s];
    int mid = (s + e) >> 1;
    int leftval = (R->l->val - L->l->val);
    if (leftval >= k)
        return query(s, mid, k, L->l, R->l);
    else
        return query(mid + 1, e, k - leftval, L->r, R->r);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    psegtree[0] = build(1, n);
    vector<int> nums(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums[i - 1] = a[i];
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        a[i] = lower_bound(nums.begin(), nums.end(), val) - nums.begin() + 1;
        id[a[i]] = val;
    }
    for (int i = 1; i <= n; i++) {
        psegtree[i] = update(psegtree[i - 1], 1, n, a[i], 1);
    }
    int l, r, k;
    while (m--) {
        cin >> l >> r >> k;
        cout << query(1, n, k, psegtree[l - 1], psegtree[r]) << '\n';
    }

    return 0;
}