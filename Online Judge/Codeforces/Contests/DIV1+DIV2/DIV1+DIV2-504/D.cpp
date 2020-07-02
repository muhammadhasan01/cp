#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;

int n, q;
int a[N];
int leftz[N], rigtz[N];
int t[4 * N], lazy[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = (a[s] == 0 ? INF : a[s]);
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

void push(int v, int s, int e) {
    if (s == e) return;
    if (lazy[v] == 0) return;
    t[v << 1] = lazy[v];
    t[v << 1 | 1] = lazy[v];
    lazy[v << 1] = lazy[v];
    lazy[v << 1 | 1] = lazy[v];
    lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r, int val) {
    if (l > r) return;
    if (l == s && e == r) {
        t[v] = val;
        lazy[v] = val;
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), val);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (l > r) return INF;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    return min(get(v << 1, s, mid, l, min(r, mid)),
            get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
}

void dismiss() {
    cout << "NO" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        leftz[i] = n + 1;
        rigtz[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        leftz[a[i]] = min(i, leftz[a[i]]);
        rigtz[a[i]] = max(i, rigtz[a[i]]);
    }
    build(1, 1, n);
    for (int val = q; val > 1; val--) {
        int mini = get(1, 1, n, leftz[val], rigtz[val]);
        if (mini < val) dismiss();
    }
    updateRange(1, 1, n, 1, n, 1);
    for (int val = 2; val <= q; val++) {
        updateRange(1, 1, n, leftz[val], rigtz[val], val);
    }
    if (leftz[q] == n + 1) {
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                updateRange(1, 1, n, i, i, q);
                flag = false;
                break;
            }
        }
        if (flag) dismiss();
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << get(1, 1, n, i, i) << (i == n ? '\n' : ' ');
    }

    return 0;
}