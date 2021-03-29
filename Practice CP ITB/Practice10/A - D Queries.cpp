#include <bits/stdc++.h>

using namespace std;

const int NMAX = 30 * 1000;
const int QMAX = 200 * 1000;
const int VMAX = 1000 * 1000;

struct s {
    int l, r, idx;
};

int n, q, block, ans = 0;
int a[NMAX + 3];
int m[VMAX + 3];


s v[QMAX + 3];
int quer[QMAX + 3];

bool cmpr(s a, s b) {
    if (a.l / block != b.l / block) {
        return a.l / block < b.l / block;
    }
    return a.r / block < b.r / block;
}

void add(int i) {
    m[a[i]]++;
    if (m[a[i]] == 1) ans++;
}

void remove(int i) {
    m[a[i]]--;
    if (m[a[i]] == 0) ans--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        v[i].l = l - 1, v[i].r = r - 1, v[i].idx = i;
    }
    block = sqrt(n);
    sort(v, v + q, cmpr);
    int cl = 0, cr = 0;
    for (int i = 0; i < q; i++) {
        int x = v[i].l, y = v[i].r;
        while (cl < x) remove(cl++);
        while (cl > x) add(--cl);
        while (cr <= y) add(cr++);
        while (cr > y + 1) remove(--cr);
        quer[v[i].idx] = ans;
    }
    for (int i = 0; i < q; i++) {
        cout << quer[i] << "\n";
    }
    
    return 0;
}