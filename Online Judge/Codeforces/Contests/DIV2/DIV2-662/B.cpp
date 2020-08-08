#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e5;

struct Segtree {
    vector<int> t;
    Segtree() {
        t.assign(4 * N, 0);
    }

    int combine(int x, int y) {
        return max(x, y);
    }

    void update(int v, int s, int e, int pos, int val) {
        if (s == e && s == pos) {
            t[v] += val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    int get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return 0;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        return combine(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
    }
};

int n, q;
int a[N];
int cnt[N];
int two = 0, four = 0;
Segtree sgt;

bool query() {
    int curtwo = two, curfour = four;
    int cur = sgt.get(1, 1, M, 1, M);
    if (cur <= 3) {
        return false;
    }
    if (cur <= 5) {
        --curtwo, --curfour;
        if (curtwo >= 2) return true;
        if (curfour >= 1) return true;
        return false;
    }
    if (cur <= 7) {
        return (curtwo >= 2);
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sgt.update(1, 1, M, a[i], 1);
        ++cnt[a[i]];
        if (cnt[a[i]] == 2) ++two;
        if (cnt[a[i]] == 4) ++four;
    }
    cin >> q;
    while (q--) {
        char tp; int x;
        cin >> tp >> x;
        if (tp == '+') {
            ++cnt[x];
            if (cnt[x] == 2) ++two;
            else if (cnt[x] == 4) ++four;
            sgt.update(1, 1, M, x, 1);
        } else {
            --cnt[x];
            if (cnt[x] == 1) --two;
            else if (cnt[x] == 3) --four;
            sgt.update(1, 1, M, x, -1);
        }
        cout << (query() ? "YES" : "NO") << '\n';
    }

    return 0;
}