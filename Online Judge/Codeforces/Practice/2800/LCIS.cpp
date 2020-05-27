#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;
const pair<int, int> NEG = {-1, -1};

int n, m;
long long a[N], b[N];
int dp[N][N];
pair<int, int> go[N][N];
pair<int, int> t[N][4 * N]; // pair of value and position

void update(int x, int v, int s, int e, int pos, const pair<int, int>& val) {
    if (s == e && s == pos) {
        t[x][v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        update(x, v << 1, s, mid, pos, val);
    } else {
        update(x, v << 1 | 1, mid + 1, e, pos, val);
    }
    t[x][v] = max(t[x][v << 1], t[x][v << 1 | 1]);
}

pair<int, int> get(int x, int v, int s, int e, int l, int r) {
    if (e < l || s > r) return NEG;
    if (l <= s && e <= r) return t[x][v];
    int mid = (s + e) >> 1;
    return max(get(x, v << 1, s, mid, l, r),
               get(x, v << 1 | 1, mid + 1, e, l, r));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] != b[j]) continue;
            int res = -1;
            for (int k = 0; k < i; k++) {
                if (a[k] >= a[i]) continue;
                pair<int, int> curres = get(k, 1, 0, m, 0, j - 1);
                if (curres.first > res) {
                    res = curres.first;
                    go[i][j] = make_pair(k, curres.second);
                }
            }
            dp[i][j] = 1 + res;
            pair<int, int> val = make_pair(dp[i][j], j);
            update(i, 1, 0, m, j, val);
        }
    }
    int ans = 0;
    pair<int, int> at;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] > ans) {
                ans = dp[i][j];
                at = make_pair(i, j);
            }
        }
    }
    deque<long long> dq;
    while (at.first > 0 && at.second > 0) {
        dq.emplace_front(a[at.first]);
        at = go[at.first][at.second];
    }
    int len = dq.size();
    assert(ans == len);
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << dq[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}