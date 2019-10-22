#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int n;
char a[2 * N + 5];

struct st {
    int l, r;
};

st t[8 * N];
st ex;

st merge(st a, st b) {
    if (a.l == -1 && a.r == -1) return b;
    if (b.l == -1 && b.r == -1) return a;
    st ret;
    int k = min(a.l, b.r);
    ret.l = a.l + b.l - k;
    ret.r = a.r + b.r - k;
    return ret;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v].l = (a[s] == '(');
        t[v].r = (a[s] == ')');
    } else {
        int mid = (s + e) >> 1;
        build(2 * v, s, mid);
        build(2 * v + 1, mid + 1, e);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

void update(int v, int s, int e, int pos, char x) {
    if (s == e) {
        t[v].l = (x == '(');
        t[v].r = (x == ')');
    } else {
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            update(2 * v, s, mid, pos, x);
        } else {
            update(2 * v + 1, mid + 1, e, pos, x);
        }
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

st get(int v, int s, int e, int l, int r) {
    if (s > r || e < l) {
        return ex;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    return merge(get(2 * v, s, mid, l, r), get(2 * v + 1, mid + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    int m = 2 * n;
    build(1, 1, m);

    int ans = 0;
    int l = 1, r = 1;

    for (int i = 1; i <= n; i++) {
        st g = get(1, 1, m, i, i + n - 1);
        if (g.l == 0 && g.l == g.r) ans++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j]) continue;
            int ret = 0;
            if (i != j) {
                update(1, 1, m, i, a[j]);
                update(1, 1, m, j, a[i]);
                update(1, 1, m, i + n, a[j]);
                update(1, 1, m, j + n, a[i]);
            }
            for (int k = 1; k <= n; k++) {
                st g = get(1, 1, m, k, k + n - 1);
                if (g.l == 0 && g.l == g.r) ret++;
            }
            if (i != j) {
                update(1, 1, m, i, a[i]);
                update(1, 1, m, j, a[j]);
                update(1, 1, m, i + n, a[i]);
                update(1, 1, m, j + n, a[j]);
            }
            if (ret > ans) {
                ans = ret;
                l = i, r = j;
            }
        }
    }
    cout << ans << '\n';
    cout << l << " " << r << '\n';

    return 0;
}
