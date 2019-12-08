#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct st {
    int k, pos, idx;
};

int n, m;
pair<int, int> a[N];
int arr[N];
int bit[N];
int ans[N];
st q[N];

bool cmpr(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

bool cstm(st a, st b) {
    if (a.k == b.k) {
        return a.pos < b.pos;
    }
    return a.k < b.k;
}

void add(int x) {
    for ( ; x <= n; x += x & -x) {
        bit[x]++;
    }
}

int get(int x) {
    int ret = 0;
    for (; x > 0; x -= x & -x) {
        ret += bit[x];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        a[i] = {arr[i], i};
    }
    sort(a + 1, a + 1 + n, cmpr);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].k >> q[i].pos;
        q[i].idx = i;
    }
    sort(q + 1, q + 1 + m, cstm);
    for (int i = 1, j = 1; i <= m; i++) {
        while (j <= q[i].k) {
            add(a[j].second);
            j++;
        }
        int l = 1, r = n, res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(mid) >= q[i].pos) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        ans[q[i].idx] = arr[res];
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
