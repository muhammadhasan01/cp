#include <iostream>
#include <vector>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

using namespace std;

struct LinkCut {
    struct Node {
        // p => parent node in the auxilary tree
        // pp => parent pointer to other auxilary tree
        // c[0] => left child, c[1] => right child in the auxilary tree
        int p = 0, c[2] = {0, 0}, pp = 0;
        bool flip = 0;
        int val = 0;
        int dp = 0;
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
        T[x].dp = T[x].val + T[l].dp + T[r].dp;
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

    void Update(int u, int val) {
        Access(u);
        T[u].val = val;
        pull(u);
    }

    int Query(int u, int v) {
        MakeRoot(u); Access(v);
        return T[v].dp;
    }
};

int main() { 
    int tc, n, q, tp, u, v;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case %d:\n", t);
        scanf("%d", &n);
        LinkCut lc(n);
        vector<int> valz(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &valz[i]);
        }
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            u++, v++;
            lc.Link(u, v);
        }
        for (int i = 0; i < n; i++) {
            lc.Update(i + 1, valz[i]);
        }
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d", &tp, &u, &v);
            if (tp) {
                u++;
                lc.Update(u, v);
            } else {
                u++, v++;
                int res = lc.Query(u, v);
                printf("%d\n", res);
            }
        }
    }

    return 0;
}