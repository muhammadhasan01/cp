#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 1e6 + 2;

int n;
int a[N];
int leftz[N][2], rightz[N][2];
int last[N];
int t[4 * N];
int part;

int merge(int x, int y) {
    if (part == 0) return max(x, y);
    return min(x, y);
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = n + 1;
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int s, int e, int pos, int val) {
    if (s == e && s == pos) {
        t[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        update(v << 1, s, mid, pos, val);
    } else {
        update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) {
        if (part == 0) return 0;
        return n + 1;
    }
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    return merge(get(v << 1, s, mid, l, r),
                 get(v << 1 | 1, mid + 1, e, l, r));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        leftz[i][0] = i - get(1, 0, M, 0, a[i]);
        leftz[i][1] = i - get(1, 0, M, a[i], M);
        update(1, 0, M, a[i], i);
    }
    part = 1;
    build(1, 0, M);
    for (int i = n; i >= 1; i--) {
        rightz[i][0] = get(1, 0, M, 0, a[i] - 1) - i;
        rightz[i][1] = get(1, 0, M, a[i] + 1, M) - i;
        update(1, 0, M, a[i], i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long mins = (1LL) * a[i] * leftz[i][0] * rightz[i][0];
        long long maks = (1LL) * a[i] * leftz[i][1] * rightz[i][1];
        ans += (maks - mins);
    }
    cout << ans << '\n';

    return 0;
}