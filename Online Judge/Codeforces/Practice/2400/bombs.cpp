#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 3e5 + 5;

int n;
int pos[N];
int t[4 * N], lazy[4 * N];

void add(int v, int val) {
    t[v] += val;
    lazy[v] += val;
}

void push(int v, int s, int e) {
    if (s == e) return;
    add(v << 1, lazy[v]);
    add(v << 1 | 1, lazy[v]);
    lazy[v] = 0;
}

void update(int v, int s, int e, int l, int r, int val) {
    if (e < l || s > r || l > r) return;
    if (l <= s && e <= r) {
        add(v, val);
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    update(v << 1, s, mid, l, r, val);
    update(v << 1 | 1, mid + 1, e, l, r, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return INF;
    if (l <= s && e <= r) {
        return t[v];
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    return min(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        pos[p] = i;
    }

    auto decrease = [&](int x) -> bool {
        update(1, 1, n, 1, pos[x], -1);
        if (get(1, 1, n, 1, pos[x]) >= 0) {
            return true;
        } else {
            update(1, 1, n, 1, pos[x], 1);
            return false;
        }
    };

    int x = n;
    for (int i = 1; i <= n; i++) {
        int q;
        cin >> q;
        while (decrease(x)) x--;
        update(1, 1, n, 1, q, 1);
        cout << x << " \n"[i == n];
    }

    return 0;
}