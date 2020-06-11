#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long M = 1e9 + 9;

int n, m;
int a[N], fib[N];
int pre[N];
int t[4 * N];
vector<int> lazy[4 * N];

long long pref(int l, int r) {
    long long ret = pre[r] - pre[l - 1];
    return (ret % M + M) % M;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = (t[v << 1] + t[v << 1 | 1]) % M;
}

void push(int v, int s, int e) {
    if (s == e) return;
    if (lazy[v].empty()) return;
    int mid = (s + e) >> 1;
    for (auto x : lazy[v]) {
        t[v << 1] = (t[v << 1] + pref(s - x, mid - x)) % M;
        t[v << 1 | 1] = (t[v << 1 | 1] + pref(mid + 1 - x, e - x)) % M;
        lazy[v << 1].emplace_back(x);
        lazy[v << 1 | 1].emplace_back(x);
    }
    lazy[v].clear();
}

void updateRange(int v, int s, int e, int l, int r, int x) {
    if (l > r) return;
    if (l == s && e == r) {
        t[v] = (t[v] + pref(s - x, e - x)) % M;
        lazy[v].emplace_back(x);
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), x);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, x);
    t[v] = (t[v << 1] + t[v << 1 | 1]) % M;
}

int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0LL;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, min(r, mid));
    int p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    return (p1 + p2) % M;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % M;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = (fib[i] + pre[i - 1]) % M;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp == 1) {
            updateRange(1, 1, n, l, r, l - 1);
        } else if (tp == 2) {
            cout << get(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}