#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];
char b[N];

struct st{
    int mini, maxi;
};

st t[4 * N];

st merge(st a, st b) {
    st ret;
    ret.mini = min(a.mini, b.mini);
    ret.maxi = max(a.maxi, b.maxi);
    return ret;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v].mini = t[v].maxi = a[s];
    } else {
        int mid = (s + e) >> 1;
        build(2 * v, s, mid);
        build(2 * v + 1, mid + 1, e);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

st get(int v, int s, int e, int l, int r) {
    if (s > r || e < l) {
        st temp;
        temp.maxi = -2e9;
        temp.mini = 2e9;
        return temp;
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
    }
    build(1, 1, n);
    b[0] = '#';
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int l = -1e9, r = 1e9;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i - 1] == '0') {
            c2 = 0;
            c1++;
        } else {
            c1 = 0;
            c2++;
        }
        if (i >= 5) {
            if (b[i] == '1' && c1 >= 4) {
                l = max(l, get(1, 1, n, i - 4, i).maxi + 1);
            } else if (b[i] == '0' && c2 >= 4) {
                r = min(r, get(1, 1, n, i - 4, i).mini - 1);
            }
        }
    }
    cout << l << " " << r << '\n';

    return 0;
}
