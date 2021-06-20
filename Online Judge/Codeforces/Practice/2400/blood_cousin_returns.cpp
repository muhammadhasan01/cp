#include <bits/stdc++.h>

using namespace std;

struct vertex {
    int val;
    vertex *l, *r;
    vertex(int val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(0), l(l), r(r) {
        if (l) val += l->val;
        if (r) val += r->val;
    }
};
typedef vertex* pvertex;

const int N = 1e5 + 5;

int n, q;
int depth[N];
int value[N], tin[N], tout[N], tim = 0;
vector<int> adj[N];
vector<int> nodes[N];
pvertex psegtree[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(0);
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos, int val) {
    if (s == e && s == pos)
        return new vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos, val));
}

int get_query(pvertex v, pvertex w, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) return v->val - w->val;
    int mid = (s + e) >> 1;
    int p1 = get_query(v->l, w->l, s, mid, l, r);
    int p2 = get_query(v->r, w->r, mid + 1, e, l, r);
    return p1 + p2;
}

void dfs(int u, int d) {
    nodes[d].emplace_back(u);
    depth[u] = d;
    tin[u] = ++tim;
    for (int v : adj[u]) {
        dfs(v, d + 1);
    }
    tout[u] = ++tim;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    map<string, int> names;
    for (int i = 1; i <= n; i++) {
        string name; int p;
        cin >> name >> p;
        value[i] = i;
        if (names.count(name)) {
            value[i] = names[name];
        } else {
            names[name] = i;
        }
        adj[p].emplace_back(i);
    }
    dfs(0, 0);
    map<pair<int, int>, int> mp;
    {
        int u = 0;
        psegtree[u] = build(0, n);
        for (int i = 0; i < N; i++) {
            if (nodes[i].empty()) {
                break;
            }
            int len = nodes[i].size();
            int cnt_0 = 0;
            unordered_map<int, int> last;
            for (int j = 0; j < len; j++) {
                u = u + 1;
                int cur = value[nodes[i][j]];
                int k = (j == 0 ? 0 : u - 1);
                bool is_zero = last.count(cur) == 0;
                if (is_zero) {
                    cnt_0 = cnt_0 + 1;
                    psegtree[u] = update(psegtree[k], 0, n, 0, cnt_0);
                } else {
                    psegtree[u] = update(psegtree[k], 0, n, last[cur], 1);
                }
                last[cur] = j + 1;
                mp[make_pair(i, j)] = u;
            }
        }
    }
    cin >> q;
    while (q--) {
        int v, k;
        cin >> v >> k;
        int tgt = min(N - 1, depth[v] + k);
        int lft = -1, rgt = -1;
        vector<int>& cur = nodes[tgt];
        {
            int l = 0, r = cur.size() - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (tin[cur[mid]] >= tin[v]) {
                    r = mid - 1;
                    lft = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        if (lft == -1) {
            cout << 0 << '\n';
            continue;
        }
        {
            int l = 0, r = cur.size() - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (tout[cur[mid]] <= tout[v]) {
                    l = mid + 1;
                    rgt = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        int pos_lft = (lft == 0 ? 0 : mp[make_pair(tgt, lft - 1)]);
        int pos_rgt = mp[make_pair(tgt, rgt)];
        int res = get_query(psegtree[pos_rgt], psegtree[pos_lft], 0, n, 0, (lft + 1) - 1);
        cout << res << '\n';
    }

    return 0;
}