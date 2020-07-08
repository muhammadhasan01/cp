#include <bits/stdc++.h>

using namespace std;

struct LinkCut {
    struct Node {
        // p => parent node in the auxilary tree
        // pp => parent pointer to other auxilary tree
        // c[0] => left child, c[1] => right child in the auxilary tree
        int p = 0, c[2] = {0, 0}, pp = 0;
        bool flip = 0;
        int val = 0, dp = 0;
    };
    vector<Node> T;

    LinkCut(int n) : T(n + 1) {}

    // SPLAY TREE OPERATIONS START

    int dir(int x, int y) { return T[x].c[1] == y; }

    void set(int x, int d, int y) {
        if (x) T[x].c[d] = y, pull(x);
        if (y) T[y].p = x;
    }

    void pull(int x) {
        if (!x) return;
        int &l = T[x].c[0], &r = T[x].c[1];
        T[x].dp = max({T[x].val, T[l].dp, T[r].dp});
    }

    void push(int x) {
        if (!x || !T[x].flip) return;
        int &l = T[x].c[0], &r = T[x].c[1];
        swap(l, r); T[l].flip ^= 1; T[r].flip ^= 1;
        T[x].flip = 0;
    }

    void rotate(int x, int d) { 
        int y = T[x].p, z = T[y].p, w = T[x].c[d];
        swap(T[x].pp, T[y].pp);
        set(y, !d, w);
        set(x, d, y);
        set(z, dir(z, y), x);
    }

    void splay(int x) { 
        for (push(x); T[x].p;) {
            int y = T[x].p, z = T[y].p;
            push(z); push(y); push(x);
            int dx = dir(y, x), dy = dir(z, y);
            if (!z) 
            rotate(x, !dx); 
            else if (dx == dy) 
            rotate(y, !dx), rotate(x, !dx); 
            else
            rotate(x, dy), rotate(x, dx);
        }
    }

    // SPLAY TREE OPERATIONS END

    void MakeRoot(int u) {
        Access(u);
        int l = T[u].c[0];
        T[l].flip ^= 1;
        swap(T[l].p, T[l].pp);
        set(u, 0, 0);
    }

    void Access(int _u) {
        for (int v = 0, u = _u; u; u = T[v = u].pp) {
            splay(u); splay(v);
            int r = T[u].c[1];
            T[v].pp = 0;
            swap(T[r].p, T[r].pp);
            set(u, 1, v);
        }
        splay(_u);
    }

    void Link(int u, int v) {
        MakeRoot(u);
        T[u].pp = v;
    }

    void Cut(int u, int v) {
        Access(u), Access(v);
        if (T[u].pp != v && T[v].pp != u) {
            Access(v), Access(u);
        }
        assert(T[u].pp == v || T[v].pp == u);
        if (T[u].pp != v)
            u = v;
        T[u].pp = 0;
        MakeRoot(u);
    }

    int LCA(int u, int v) {
        if (u == v) return u;
        Access(u), Access(v);
        while (T[v].c[0]) {
            v = T[v].c[0];
            if (v == u) {
                splay(v);
                return v;
            }
        }
        while (T[u].c[0]) u = T[u].c[0];
        splay(u);
        return T[u].pp;
    }
};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    LinkCut lc(n);
    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);
    string s; int u, v;
    while (m--) {
        cin >> s;
        if (s[1] == 'i') {
            cin >> u >> v;
            par[u] = v;
            lc.Link(u, v);
        } else if (s[1] == 'u') {
            cin >> u;
            assert(u != par[u]);
            lc.Cut(u, par[u]);
            par[u] = u;
        } else {
            cin >> u >> v;
            cout << lc.LCA(u, v) << '\n';
        }
    }

    return 0;
}