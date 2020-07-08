#include <bits/stdc++.h>

using namespace std;

struct LinkCut {
    struct Node {
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
        // assert(!Connected(u, v));
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

    bool Connected(int u, int v) {
        if (u == v) return true;
        int r_1 = FindRoot(u);
        int r_2 = FindRoot(v);
        return (r_1 == r_2);
    }

    int FindRoot(int u) {
        Access(u);
        while (T[u].c[0]) u = T[u].c[0];
        splay(u);
        return u;
    }
};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    LinkCut lc(n);
    string s; int u, v;
    while (m--) {
        cin >> s >> u >> v;
        if (s[0] == 'a') {
            lc.Link(u, v);
        } else if (s[0] == 'r') {
            lc.Cut(u, v);
        } else {
            cout << (lc.Connected(u, v) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}