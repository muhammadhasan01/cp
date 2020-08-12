#include <bits/stdc++.h>

using namespace std;

const int N = 6e4 + 5;
const int K = 26;
const int Q = 4e4 + 5;

string T;
int q, A, B;
string s[Q];
int posVertex[Q];
vector<int> adj[N];
int depth[N], head[N], heavy[N];
int par[N], id[N], pos[N];
int curPos;

struct SegtreeLazy {
    vector<int> t, lazy;
    SegtreeLazy() {
        t.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }

    int combine(int x, int y) {
        return (x > y ? x : y);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        t[v << 1] += lazy[v];
        t[v << 1 | 1] += lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, int val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] += val;
            lazy[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    int get(int v, int s, int e, int l, int r) {
        if (l > r)
            return 0;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        return combine(get(v << 1, s, mid, l, min(r, mid)), 
                get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
    }
} sgtlazy;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int dfs(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    par[u] = p;
    int sz = 1, max_sz = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        int res = dfs(v, u);
        sz += res;
        if (res > max_sz)
            max_sz = res, heavy[u] = v; 
    }
    return sz;
}

void decompose(int u, int h) {
    head[u] = h, pos[u] = ++curPos;
    id[curPos] = u;
    if (heavy[u])
        decompose(heavy[u], h);
    for (auto v : adj[u])
        if (v != par[u] && v != heavy[u])
            decompose(v, v);
}

void updatePath(int u, int v) {
    int res = 0;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        sgtlazy.update(1, 1, curPos, pos[head[u]], pos[u], 1);
    }
    if (depth[u] > depth[v]) swap(u, v); // u will be the LCA
    sgtlazy.update(1, 1, curPos, pos[u], pos[v], 1);
}

int getVertexCnt(int u) {
    return sgtlazy.get(1, 1, curPos, pos[u], pos[u]);
}

void init_HLD() {
    dfs(0, 0);
    decompose(0, 0);
}

void init_graph() {
    int len = t.size() - 1;
    for (int u = 1; u <= len; u++) {
        int v = get_link(u);
        adj[v].emplace_back(u);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    cin >> q >> A >> B;
    for (int i = 1; i <= q; i++) {
        cin >> s[i];
        posVertex[i] = add_string(s[i]);
    }
    init_graph();
    init_HLD();
    int curVertex = 0;
    for (char ch : T) {
        curVertex = go(curVertex, ch);
        updatePath(0, curVertex);
    }
    for (int i = 1; i <= q; i++) {
        int C = getVertexCnt(posVertex[i]);
        cout << C << '\n';
        char nextVertex = char(int('a') + (A * C + B) % K);
        curVertex = go(curVertex, nextVertex);
        updatePath(0, curVertex);
    }

    return 0;
}