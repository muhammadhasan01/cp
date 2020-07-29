#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

struct segtree {
    vector<int> t;
    segtree() {
        t.assign(4 * (N + 1), 0);
    }
    void update(int v, int s, int e, int pos, int val) {
        if (s == e && s == pos) {
            t[v] += val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    int get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return 0;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        return get(v << 1, s, mid, l, r) + get(v << 1 | 1, mid + 1, e, l, r);
    }
};


int d;
int n, m;
int s[N + 5][4];
int cnt[4]; // left, right, top, bottom;
segtree sgt[4];

void upd(int i, int val) {
    for (int it = 0; it < 4; it++) {
        sgt[it].update(1, 1, N, s[i][it], val);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> n >> m;
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> s[i][j];
        }
        if (s[i][0] > s[i][2]) swap(s[i][0], s[i][2]);
        if (s[i][1] > s[i][3]) swap(s[i][1], s[i][3]);
        upd(i, 1);
    }
    for (int i = 0; i < 4; i++) {
        cin >> cnt[i];
    }
    for (int i = 1; i <= d; i++) {
        upd(i, -1);
        int curL = sgt[0].get(1, 1, N, 1, s[i][2] - 1);
        int curR = sgt[2].get(1, 1, N, s[i][0] + 1, N);
        int curT = sgt[1].get(1, 1, N, 1, s[i][3] - 1);
        int curB = sgt[3].get(1, 1, N, s[i][1] + 1, N);
        if (curL == cnt[0] && curR == cnt[1] && curT == cnt[2] && curB == cnt[3]) {
            cout << i << '\n';
            return 0;
        }
        upd(i, 1);
    }
    cout << -1 << '\n';

    return 0;
}