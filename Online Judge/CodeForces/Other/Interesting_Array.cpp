#include <bits/stdc++.h>
using namespace std;

struct st{
    int l, r, q;
};

const int N = 1e5 + 5;
const int B = 30;
const int P = (1LL << B) - 1;
int n, m;
int pre[N], ans[N];
st a[N];
int t[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = ans[s];
    } else {
        int mid = (s + e) >> 1;
        build(2 * v, s, mid);
        build(2 * v + 1, mid + 1, e);
        t[v] = (t[2 * v] & t[2 * v + 1]);
    }
}

int get(int v, int s, int e, int l, int r) {
    if (s > r || e < l) {
        return P;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    int p1 = get(2 * v, s, mid, l, r);
    int p2 = get(2 * v + 1, mid + 1, e, l, r);
    return (p1 & p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> a[i].l >> a[i].r >> a[i].q;
    }
    for (int bit = 0; bit <= B - 1; bit++) {
        for (int i = 1; i <= n; i++) pre[i] = 0;
        for (int i = 1; i <= m; i++) {
            if (a[i].q & (1LL << bit)) {
                pre[a[i].l]++;
                pre[a[i].r + 1]--;
            }
        }
        for (int i = 1; i <= n; i++) {
            pre[i] += pre[i - 1];
            if (pre[i] > 0) {
                ans[i] |= (1LL << bit);
            }
        }
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        if (get(1, 1, n, a[i].l, a[i].r) != a[i].q) {
            puts("NO");
            return 0;
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
