#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
bitset<13> a[N];

int t[4 * N][11], ans;

int merge(int a, int b) {
    return a + b;
}

void build (int v, int s, int e, int k) {
    if (s == e) {
        if (a[s][k] == 1) {
            t[v][k] = 1;
        } else {
            t[v][k] = 0;
        }
    } else {
        int mid = (s + e) >> 1;
        build(2 * v, s, mid, k);
        build(2 * v + 1, mid + 1, e, k);
        t[v][k] = merge(t[2 * v][k], t[2 * v + 1][k]);
    }
}

void update (int v, int s, int e, int pos, int k) {
    if (s == e) {
        t[v][k] = 1 - t[v][k];
    } else {
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            update(2 * v, s, mid, pos, k);
        } else {
            update(2 * v + 1, mid + 1, e, pos, k);
        }
        t[v][k] = merge(t[2 * v][k], t[2 * v + 1][k]);
    }
}

int query(int v, int s, int e, int l, int r, int k) {
    if (s > r || e < l) {
        return 0;
    }
    if (l <= s && e <= r) {
        return t[v][k];
    }
    int mid = (s + e) >> 1;
    return merge(query(2 * v, s, mid, l, r, k), query(2 * v + 1, mid + 1, e, l, r, k));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool k;
            cin >> k;
            a[j][i] = (k ? 1 : 0);
        }
        build(1, 1, m, i);
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "ON") {
            ans = 0;
            for (int i = 1; i <= n; i++) {
                ans += query(1, 1, m, 1, m, i);
            }
        } else if (s == "OFF") {
            ans = 0;
            for (int i = 1; i <= n; i++) {
                ans += m - query(1, 1, m, 1, m, i);
            }
        } else if (s[0] == 'C') {
            int k, l, r;
            cin >> k >> l >> r;
            ans = query(1, 1, m, l, r, k);
        } else if (s[0] == 'F') {
            int x;
            cin >> x;
            int anss = -1, pos = -1;
            for (int i = 1; i <= n; i++) {
                int k = query(1, 1, m, 1, m, i);
                if (x > k) {
                    x -= k;
                } else {
                    int l = 1, r = m;
                    while (l <= r) {
                        int mid = (l + r) >> 1;
                        if (query(1, 1, m, 1, mid, i) >= x) {
                            r = mid - 1;
                            anss = i;
                            pos = mid;
                        } else {
                            l = mid + 1;
                        }
                    }
                    break;
                }
            }
            if (pos == -1) {
                cout << pos << '\n';
                continue;
            } else {
                cout << anss << " " << pos << '\n';
                continue;
            }
        } else if (s[0] == 'T') {
            int u, v;
            cin >> u >> v;
            update(1, 1, m, v, u);
            cout << "DONE" << '\n';
            continue;
        }
        cout << ans << '\n';
    }

    return 0;
}
