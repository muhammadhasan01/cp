#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n;
string s;
int a[N];

struct st {
    int maxi, mini, lazy;
};

st t[4 * N];

st merge(st a, st b) {
    return {max(a.maxi, b.maxi), min(a.mini, b.mini), 0};
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = {0, 0, 0};
    } else {
        int mid = (s + e) / 2;
        build(2 * v, s, mid);
        build(2 * v + 1, mid + 1, e);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

void update(int v, int val) {
    t[v].lazy += val;
    t[v].maxi += val;
    t[v].mini += val;
}

void push(int v, int s, int e) {
    if (t[v].lazy == 0) return;
    update(2 * v, t[v].lazy);
    update(2 * v + 1, t[v].lazy);
    t[v].lazy = 0;
}

void updateRange(int v, int s, int e, int l, int r, int val) {
    if (l <= s && e <= r) {
        return update(v, val);
    }
    push(v, s, e);
    int mid = (s + e) / 2;
    if (l <= mid) {
        updateRange(2 * v, s, mid, l, r, val);
    }
    if (mid < r) {
        updateRange(2 * v + 1, mid + 1, e, l, r, val);
    }
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    build(1, 1, n);
    int pos = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            pos = max(1, pos - 1);
        } else if (s[i] == 'R') {
            pos++;
        } else if (s[i] == '(') {
            updateRange(1, 1, n, pos, n, -1 - a[pos]);
            sum += -1 - a[pos];
            a[pos] = -1;
        } else if (s[i] == ')') {
            updateRange(1, 1, n, pos, n, 1 - a[pos]);
            sum += 1 - a[pos];
            a[pos] = 1;
        } else {
            updateRange(1, 1, n, pos, n, -a[pos]);
            sum += -a[pos];
            a[pos] = 0;
        }
        cout << (sum == 0 && t[1].maxi == 0 ? -t[1].mini : -1) << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
