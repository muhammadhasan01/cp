#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], f[N], res[N];
int bl;
map<int, int> mp;

struct st{
    int le, ri, idx;
};

st q[N];

int ans = 0, cl = 1, cr = 1;

bool cmpr(st a, st b) {
    if (a.le / bl == b.le / bl) {
        return a.ri < b.ri;
    }
    return a.le / bl < b.le / bl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].le >> q[i].ri;
        q[i].idx = i;
    }
    bl = sqrt(m + 1);
    sort(q + 1, q + 1 + m, cmpr);
    for (int i = 1; i <= m; i++) {
        int l = q[i].le, r = q[i].ri;
        while (cl < l) {
            if (a[cl] <= n) {
                if (f[a[cl]] == a[cl]) ans--;
                f[a[cl]]--;
                if (f[a[cl]] == a[cl]) ans++;
            }
            cl++;
        }
        while (cl > l) {
            if (a[cl - 1] <= n) {
                if (f[a[cl - 1]] == a[cl - 1]) ans--;
                f[a[cl - 1]]++;
                if (f[a[cl - 1]] == a[cl - 1]) ans++;
            }
            cl--;
        }
        while (cr <= r) {
            if (a[cr] <= n) {
                if (f[a[cr]] == a[cr]) ans--;
                f[a[cr]]++;
                if (f[a[cr]] == a[cr]) ans++;
            }
            cr++;
        }
        while (cr > r + 1) {
            if (a[cr - 1] <= n) {
                if (f[a[cr - 1]] == a[cr - 1]) ans--;
                f[a[cr - 1]]--;
                if (f[a[cr - 1]] == a[cr - 1]) ans++;
            }
            cr--;
        }
        res[q[i].idx] = ans;
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}
