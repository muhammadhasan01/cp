// source: [retrogad](https://codeforces.com/blog/entry/75885)
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
    assert(!Connected(u, v));
    MakeRoot(v);
    T[v].pp = u;
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
 
  int GetPath(int u, int v) {
    MakeRoot(u); Access(v); return v;
  }
};
 
void Test() {
  int N = 100, Q = 100, V = 1000;
  do {
    int n = rand() % N + 1;
    int q = rand() % Q + 1;
    int p1 = rand() % 100, p2 = rand() % 100, p3 = rand() % 100, p4 = rand() % 100, p5 = rand() % 100;
 
    vector<pair<int, int>> edges;
    LinkCut lc(n);
 
    auto conn = [&](int a, int b) {
      vector<int> dp(n + 1, -1);
      dp[a] = lc.T[a].val;
      for (int ch = 1; ch >= 0; ch--) {
        for (auto p : edges) {
          for (int it = 0; it < 2; ++it) {
            if (dp[p.first] != -1 && dp[p.second] == -1) {
              dp[p.second] = max(dp[p.first], lc.T[p.second].val);
              ch = 1;
            }
            swap(p.first, p.second);
          }
        }
      }
      return dp[b];
    };
 
 
    auto sim_op = [&]() {
      while (true) {
        int t = rand() % (p1 + p2 + p3 + p4 + p5);
 
        if (t < p1) {
          int a = rand() % n + 1, b = rand() % n + 1;
          if (conn(a, b) == -1) {
            edges.emplace_back(a, b);
            lc.Link(a, b);
            return;
          }
          continue;
        }
 
        t -= p1;
       
        if (t < p2) {
          if (edges.empty()) continue;
          int pos = rand() % edges.size();
          swap(edges[pos], edges.back());
          // cerr << "CUT: " << edges.back().first << " " << edges.back().second << endl;
          lc.Cut(edges.back().first, edges.back().second);
          edges.pop_back();
          return;
        }
 
        t -= p2;
       
        if (t < p3) {
          int node = rand() % n + 1;
          lc.Access(node);
          lc.T[node].val = rand() % V + 1;
          lc.pull(node);
          // cerr << "UPDATE: " << node << endl;
          return;
        }
 
        t -= p3;
 
        if (t < p4) {
          int a = rand() % n + 1, b = rand() % n + 1;
          int expected = conn(a, b);
          if (expected != -1) {
            // cerr << "QUERY: " << a << " " << b << endl;
            int c = lc.GetPath(a, b);
            int actual = lc.T[c].dp;
            assert(expected == actual);
            return;
          }
          continue;
        }
 
        t -= p4;
 
        if (t < p5) {
          int a = rand() % n + 1, b = rand() % n + 1;
          // cerr << "CONNECTED: " << a << " " << b << endl;
          int expected = (conn(a, b) != -1);
          // cerr << "EXP: " << expected << endl;
          int actual = lc.Connected(a, b);
          assert(expected == actual);
          return;
        }
 
        assert(false);
      }
    };
 
    for (int i = 0; i < q; ++i) {
      sim_op();
    }
 
    cerr << "OK N = " << n << " Q = " << q << endl;
  } while (false);
}
 
int main() {
  Test();
  return 0;
}