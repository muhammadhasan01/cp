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

int n;
int a[N];
pvertex psegtree[N];

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

int getKth(pvertex v, int s, int e, int k) {
    if (s == e) {
        return s;
    }
    int mid = (s + e) >> 1;
    int lft = v->l->val;
    if (lft >= k) {
        return getKth(v->l, s, mid, k);
    } else {
        return getKth(v->r, mid + 1, e, k - lft);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> last(n + 1);
    psegtree[n + 1] = build(1, n + 1);
    for (int i = n; i >= 1; i--) {
        psegtree[i] = update(psegtree[i + 1], 1, n + 1, i, 1);
        if (last[a[i]] > 0) {
            psegtree[i] = update(psegtree[i], 1, n + 1, last[a[i]], 0);
        }
        last[a[i]] = i;
    }
    for (int k = 1; k <= n; k++) {
        int ans = 0;
        for (int i = 1; i <= n; ++ans) {
            int pos = getKth(psegtree[i], 1, n + 1, k + 1) - 1;
            i = pos + 1;
        }
        cout << ans << " \n"[k == n];
    }

    return 0;
}