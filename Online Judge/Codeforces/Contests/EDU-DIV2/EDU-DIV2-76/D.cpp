#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n, m;
int a[N];
int t[4 * N];
pair<int, int> p[N];
int suf[N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = a[s];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

int get(int v, int s, int e, int l, int r) {
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    return max(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

bool can(int x, int y) {
    int maks = get(1, 1, n, x, y);
    int l = 1, r = m, pos = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (p[mid].first >= maks) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int len = y - x + 1;
    return (pos != -1 && suf[pos] >= len);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        int maks = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            maks = max(maks, a[i]);
        }
        build(1, 1, n);
        cin >> m;
        int maks2 = -1;
        for (int i = 1; i <= m; i++) {
            cin >> p[i].first >> p[i].second;
            maks2 = max(maks2, p[i].first);
        }

        if (maks > maks2) {
            cout << -1 << '\n';
            continue;
        }

        sort(p + 1, p + 1 + m);

        suf[m + 1] = 0;
        for (int i = m; i >= 1; i--) suf[i] = max(suf[i + 1], p[i].second);

        int ans = 0;
        int i = 1;
        while (i <= n) {
            int l = i, r = n;
            int pos = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (can(i, mid)) {
                    l = mid + 1;
                    pos = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans++;
            i = pos + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
