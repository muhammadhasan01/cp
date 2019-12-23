#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;
int n, q;
long long a[N];
long long lazy[4 * N], t[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = a[s];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

void updateRange(int v, int s, int e, int l, int r, long long val) {
    if (lazy[v] != 0) {
        t[v] += lazy[v];
        if (s != e) {
            lazy[v << 1] += lazy[v];
            lazy[v << 1 | 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (s > r || e < l) {
        return;
    }
    if (l <= s && e <= r) {
        t[v] += val;
        if (s != e) {
            lazy[v << 1] += val;
            lazy[v << 1 | 1] += val;
        }
        return;
    }

    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, r, val);
    updateRange(v << 1 | 1, mid + 1, e, l, r, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

long long queryRange(int v, int s, int e, int l, int r) {
    if (s > r || e < l) {
        return INF;
    }
    if (lazy[v] != 0) {
        t[v] += lazy[v];
        if (s != e) {
            lazy[v << 1] += lazy[v];
            lazy[v << 1 | 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    long long q1 = queryRange(v << 1, s, mid, l, r);
    long long q2 = queryRange(v << 1 | 1, mid + 1, e, l, r);
    return min(q1, q2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    cin.ignore();
    while (q--) {
        string s;
        getline(cin, s);
        int k1 = -1, k2 = -1;
        long long k3 = INF;
        string cur = "";
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == ' ') {
                if (k1 == -1) {
                    k1 = stoi(cur);
                } else if (k2 == -1) {
                    k2 = stoi(cur);
                }
                cur = "";
            } else {
                cur += s[i];
            }
        }
        if (k1 != -1 && k2 == -1) {
            k2 = stoi(cur);
        } else if (k2 != -1) {
            k3 = stoi(cur);
        }
        if (k3 == INF) {
            if (k1 <= k2) {
                cout << queryRange(1, 1, n, k1 + 1, k2 + 1) << '\n';
            } else {
                cout << min(queryRange(1, 1, n, k1 + 1, n), queryRange(1, 1, n, 1, k2 + 1)) << '\n';
            }
        } else {
            if (k1 <= k2) {
                updateRange(1, 1, n, k1 + 1, k2 + 1, k3);
            } else {
                updateRange(1, 1, n, k1 + 1, n, k3);
                updateRange(1, 1, n, 1, k2 + 1, k3);
            }
        }
    }

    return 0;
}
