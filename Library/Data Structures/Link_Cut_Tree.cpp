// source : [retrogad](https://codeforces.com/blog/entry/75885)
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
        int vir = 0, sz = 0; // Maintain subtree information
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
        T[x].sz = 1 + T[x].vir + T[l].sz + T[r].sz;
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
        T[u].vir += T[l].sz;
        swap(T[l].p, T[l].pp);
        set(u, 0, 0);
    }

    void Access(int _u) {
        for (int v = 0, u = _u; u; u = T[v = u].pp) {
            splay(u); splay(v);
            int r = T[u].c[1];
            T[v].pp = 0;
            // update the size of virtual subtree
            T[u].vir -= T[v].sz; 
            T[u].vir += T[r].sz;
            swap(T[r].p, T[r].pp);
            set(u, 1, v);
        }
        splay(_u);
    }

    void Link(int u, int v) { 
        assert(!Connected(u, v));
        MakeRoot(u);
        T[u].pp = v;
        T[v].vir += T[u].sz;
    }

    void Cut(int u, int v) {
        MakeRoot(u); Access(u); splay(v);
        assert(T[v].pp == u);
        T[v].pp = 0;
        T[u].vir -= T[v].sz;
    }
    
    // par[u] = v or par[v] = u
    void CutRoot(int u, int v) {
        Access(u), Access(v);
        if (T[u].pp != v && T[v].pp != u) {
            Access(v), Access(u);
        }
        assert(T[u].pp == v || T[v].pp == u);
        if (T[u].pp != v)
            u = v;
        T[u].pp = 0;
        T[v].vir -= T[u].sz;
        MakeRoot(u);
    }

    bool Connected(int u, int v) {
        if (u == v) return true;
        MakeRoot(u); Access(v); splay(u);
        return T[v].p == u || T[T[v].p].p == u;
    }

    bool Connected_(int u, int v) {
        if (u == v) return true;
        int r_1 = FindRoot(u);
        int r_2 = FindRoot(v);
        return (r_1 == r_2);
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

    int FindRoot(int u) {
        Access(u);
        while (T[u].c[0]) u = T[u].c[0];
        splay(u);
        return u;
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
    return 0;
}