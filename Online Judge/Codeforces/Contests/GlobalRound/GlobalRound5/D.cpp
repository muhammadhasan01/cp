#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];
pair<int,int> b[N];
int ans[N];
vector<int> bit[N];

void add(int x, int val) {
    for (; x <= n; x += x & -x) {
        bit[x].push_back(val);
    }
}

int get(int x, int val) {
    int ret = N;
    for (; x > 0; x -= x & -x) {
        auto it = lower_bound(bit[x].begin(), bit[x].end(), val);
        if (it != bit[x].end()) {
            ret = min(ret, *it);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        b[i].first = a[i];
        b[i].second = i;
    }

    int m = n;

    sort(b + 1, b + 1 + m);

    for (int i = 1; i <= m; i++) {
        add(i, b[i].second);
        add(i, b[i].second + n);
    }

    for (int i = 1; i <= m; i++) {
        sort(bit[i].begin(), bit[i].end());
    }

    set<int> s;
    int x, y;
    for (int i = m; i >= 1; i--) {
        x = b[i].first, y = b[i].second;
        int need = (x % 2 == 0 ? x / 2 - 1 : x / 2);
        int l = 1, r = n, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (b[mid].first <= need) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        if (i == m) {
            if (pos == -1) {
                ans[y] = -1;
            } else {
                int idx = get(pos, y);
                ans[y] = idx - y;
            }
        } else {
            int gpos = *s.lower_bound(y);
            if (pos == -1) {
                int dif = gpos - y;
                if (gpos > n) gpos -= n;
                ans[y] = (ans[gpos] == -1 ? -1 : ans[gpos] + dif);
            } else {
                int idx = get(pos, y);
                if (idx - y < gpos - y) {
                    ans[y] = idx - y;
                } else {
                    int dif = gpos - y;
                    if (gpos > n) gpos -= n;
                    ans[y] = (ans[gpos]  == -1 ? -1 : ans[gpos] + dif);
                }
            }
        }
        s.insert(y);
        s.insert(y + n);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
