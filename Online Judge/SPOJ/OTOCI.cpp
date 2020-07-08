#include <bits/stdc++.h>

using namespace std;

// source : [retrogad](https://codeforces.com/blog/entry/75885)
struct LinkCut {
    struct Node {
        // p => parent node in the auxilary tree
        // pp => parent pointer to other auxilary tree
        // c[0] => left child, c[1] => right child in the auxilary tree
        int p = 0, c[2] = {0, 0}, pp = 0;
        bool flip = 0;
        int val = 0;
        long long dp = 0;
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
        T[x].dp = (1LL) * T[x].val + T[l].dp + T[r].dp;
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
        if (Connected(u, v)) {
            cout << "no" << '\n';
            return;
        }
        cout << "yes" << '\n';
        MakeRoot(u);
        T[u].pp = v;
    }

    void Cut(int u, int v) {
        MakeRoot(u); Access(u); splay(v);
        assert(T[v].pp == u);
        T[v].pp = 0;
    }

    bool Connected(int u, int v) {
        if (u == v) return true;
        MakeRoot(u); Access(v); splay(u);
        return T[v].p == u || T[T[v].p].p == u;
    }

    void Update(int u, int val) {
        Access(u);
        T[u].val = val;
        pull(u);
    }

    int Query(int u, int v) {
        MakeRoot(u); Access(v);
        return T[v].dp;
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

    int n;
    cin >> n;
    LinkCut lc(n);
    for (int i = 1; i <= n; i++) {
        cin >> lc.T[i].val;
    }
    int q, u, v; string s;
    cin >> q;
    while (q--) {
        cin >> s >> u >> v;
        if (s[0] == 'b') {
            lc.Link(u, v);
        } else if (s[0] == 'p') {
            lc.Update(u, v);
        } else if (s[0] == 'e') {
            if (lc.Connected(u, v))
                cout << lc.Query(u, v) << '\n';
            else
                cout << "impossible" << '\n';
        }
    }

    return 0;
}