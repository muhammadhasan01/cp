#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const pair<int, int> TERM = {0, 0};

struct query {
    int t, x, y;
};

struct segtree {
    vector<pair<int, int>> t;

    segtree() {
        t.resize(4 * 3 * N);
    }

    void update(int v, int s, int e, int pos, const pair<int, int>& val) {
        if (s == e && s == pos) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    pair<int, int> get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r) return TERM;
        if (l <= s && e <= r) return t[v];
        int mid = (s + e) >> 1;
        return max(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
    }
};

int n;
query q[N];
int lx[N], rx[N];
set<int> st;
unordered_map<int, int> idx;
segtree sl, sr;

bool validate(int i, int j) {
    long long dx = q[i].x - q[j].x; dx *= dx;
    long long dy = q[i].y - q[j].y; dy *= dy;
    long long dm = q[i].y; dm *= dm;
    return (dx + dy < dm);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i].t >> q[i].x >> q[i].y;
        if (q[i].t == 1) {
            st.emplace(q[i].x - q[i].y);
            st.emplace(q[i].x + q[i].y);
        } else {
            st.emplace(q[i].x);
        }
    }
    int cnt_x = 0;
    for (auto& x : st) {
        idx[x] = ++cnt_x;
    }
    for (int i = 1; i <= n; i++) {
        if (q[i].t == 1) {
            rx[i] = idx[q[i].x + q[i].y];
            lx[i] = idx[q[i].x - q[i].y];
            pair<int, int> val = make_pair(2 * q[i].y, i);
            sr.update(1, 1, cnt_x, rx[i], val);
            sl.update(1, 1, cnt_x, lx[i], val);
        } else {
            int cx = idx[q[i].x];
            // Search for the right part
            int l = cx + 1, r = cnt_x, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                auto cur = sr.get(1, 1, cnt_x, cx + 1, mid);
                if (cur.first > q[i].y) {
                    r = mid - 1;
                    at = cur.second;
                } else {
                    l = mid + 1;
                }
            }
            if (at != -1 && validate(at, i)) {
                cout << at << '\n';
                sr.update(1, 1, cnt_x, rx[at], TERM);
                sl.update(1, 1, cnt_x, lx[at], TERM);
                continue;
            }
            // If not yet found
            // Search for the left part
            l = 1, r = cx - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                auto cur = sl.get(1, 1, cnt_x, mid, cx - 1);
                if (cur.first > q[i].y) {
                    l = mid + 1;
                    at = cur.second;
                } else {
                    r = mid - 1;
                }
            }
            if (at != -1 && validate(at, i)) {
                cout << at << '\n';
                sr.update(1, 1, cnt_x, rx[at], TERM);
                sl.update(1, 1, cnt_x, lx[at], TERM);
                continue;
            }
            cout << -1 << '\n';
        }
    }

    return 0;
}