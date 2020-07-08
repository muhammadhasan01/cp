#include <bits/stdc++.h>

using namespace std;

struct LinkCut {
    struct Node {
        // p => parent node in the auxilary tree
        // pp => parent pointer to other auxilary tree
        // c[0] => left child, c[1] => right child in the auxilary tree
        int p = 0, c[2] = {0, 0}, pp = 0;
        bool flip = 0;
        int vir = 0, sz = 0; // Maintaining subtree information
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
        MakeRoot(u);
        T[u].pp = v;
        T[v].vir += T[u].sz;
    }

    long long Query(int u, int v) {
        MakeRoot(u); Access(v);
        return (1LL) * (1 + T[u].vir) * (1 + T[v].vir);
    }
};

int n, q;
char tp;
int u, v;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    LinkCut lc(n);
    while (q--) {
        cin >> tp >> u >> v;
        if (tp == 'A') {
            lc.Link(u, v);   
        } else if (tp == 'Q') {
            cout << lc.Query(u, v) << "\n";
        }
    }

    return 0;
}