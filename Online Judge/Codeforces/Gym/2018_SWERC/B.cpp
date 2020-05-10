// author : m.hasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
pair<int, int> p[N];
int ans = 0;

pair<int, int> t[4 * N];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = p[s];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

pair<int, int> get(int v, int s, int e, int l, int r) {
    if (e < l || s > r) return {-N, N};
    if (l <= s && e <= r) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    return merge(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

void check(int x, int y, int z, int k) {
    int left_bnd = (z == 0 ? x : n - x + 1);
    int right_bnd = (k == 0 ? y : n - y + 1);
    int l = 1, r = min(left_bnd, right_bnd), cur = 0;
    pair<int, int> temp;
    while (l <= r) {
        int mid = (l + r) >> 1;
        bool flag = true;
        if (z) {
            temp = get(1, 1, n, x, x + mid - 1);
        } else {
            temp = get(1, 1, n, x - mid + 1, x);
        }
        if (k) {
            if (temp.first > y || temp.second < y + mid - 1) {
                flag = false;
            }
        } else {
            if (temp.first > y - mid + 1 || temp.second < y) {
                flag = false;
            }
        }
        if (flag) {
            l = mid + 1;
            cur = mid;
        } else {
            r = mid - 1;
        }
    }
    ans = max(ans, cur);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        p[i].first++;
        p[i].second++;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                check(i, p[i].first, j, k);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}