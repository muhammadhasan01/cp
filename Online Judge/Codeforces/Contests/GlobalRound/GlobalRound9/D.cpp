#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int INF = 1e9;
const pii TERM = {INF, INF};

int tc;
int n, a[N];
pii t[4 * N];
int cnt[N];
vector<int> pos[N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = make_pair(cnt[s], s);
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int s, int e, int pos, int val) {
    if (s == e && s == pos) {
        t[v].first += val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
        update(v << 1, s, mid, pos, val);
    else
        update(v << 1 | 1, mid + 1, e, pos, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

pii getRange(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return TERM;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    return min(getRange(v << 1, s, mid, l, r), getRange(v << 1 | 1, mid + 1, e, l, r));
}

void solve() {
    cin >> n;
    int m = n + 3;
    for (int i = 0; i <= m; i++) {
        cnt[i] = 0;
        pos[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        pos[a[i]].emplace_back(i);
    }
    build(1, 0, m);
    vector<int> ans;
    for (int it = 0; it < 2 * n; it++) {
        int cur = getRange(1, 0, m, 0, m).second;
        if (cur >= n) {
            int pos = 1;
            while (a[pos] == pos - 1) ++pos;
            if (pos > n) break;
            for (int j = 1; j <= n; j++) {
                if (a[j] == pos - 1) {
                    pos = j;
                    break;
                }
            }
            ans.emplace_back(pos);
            update(1, 0, m, a[pos], -1);
            update(1, 0, m, cur, 1);
            a[pos] = cur;
            continue;
        }
        ans.emplace_back(cur + 1);
        update(1, 0, m, a[cur + 1], -1);
        update(1, 0, m, cur, 1);
        a[cur + 1] = cur;
    }
    for (int i = 1; i < n; i++) {
        assert(a[i] <= a[i + 1]);
    }
    int len = ans.size();
    assert(len <= 2 * n);
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    } 
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}