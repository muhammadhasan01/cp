#include<bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int NMAX = 50 * 1000;

struct s {
    long long j, p, s, ans;
};

s tree[10 * NMAX + 3];
int a[NMAX + 3];
int n, temp;

s create(int x) {
    s temp;
    temp.j = temp.ans = temp.p = temp.s = x;
    return temp;
}

s merge(s a, s b) {
    s x;
    x.j = a.j + b.j;
    x.p = max(a.p, a.j + b.p);
    x.s = max(a.s + b.j, b.s);
    x.ans = max(max(a.ans, b.ans), a.s + b.p);
    return x;
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = create(a[start]);
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

s query(int node, int start, int end, int l, int r) {
    if (l > r) {
        return create(-INF);
    }
    if (l <= start && end <= r) {
        return tree[node];
    } else {
        int mid = (start + end) / 2;
        return merge(query(2 * node, start, mid, l, min(r, mid)), query(2 * node + 1, mid + 1, end, max(l, mid + 1), r));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << a[l] << "\n";
        } else {
            cout << query(1, 1, n, l, r).ans << "\n";
        }
    }
    return 0;
}