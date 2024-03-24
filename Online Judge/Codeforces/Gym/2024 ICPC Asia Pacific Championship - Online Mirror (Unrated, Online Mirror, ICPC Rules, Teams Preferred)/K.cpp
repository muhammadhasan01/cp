#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

constexpr int kNode = 1e5 + 10;

// ordered_set X;

// int main() {
//     cout<<*X.find_by_order(1)<<endl;          // array index ke-1
//     cout<<(end(X)==X.find_by_order(6))<<endl; // end(X) = pointer
//     cout<<X.order_of_key(400)<<endl;          // idx lower_bound 400
// }

struct Query {
  long long order;
  int x;
  int y;
  int lca;
};

struct BIT {
  vector<long long> bit;
  vector<int> vec;
  int n;

  BIT(int sz) : n(sz + 10), bit(n, 0), vec(n, 0) {}

  void update(int x, int val) {
    x++;
    int del = val - vec[x];
    vec[x] = val;
    while (x < n) {
      bit[x] += del;
      x += (x & (-x));
    }
  }

  long long ask(int x) {
    x++;
    long long ret = 0;
    while (x > 0) {
      ret += bit[x];
      x -= (x & (-x));
    }
    return ret;
  }
};

struct UnionOrdered {
  int n;
  vector<int> par, sz;
  vector<ordered_set> pbds;

  UnionOrdered(int n) : n(n), par(n), sz(n), pbds(n) {
    for (int i = 0; i < n; i++) {
      par[i] = i;
      pbds[i].insert(i);
    }
  }

  int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (pbds[a].size() < pbds[b].size()) swap(a, b);
    for (auto x : pbds[b]) pbds[a].insert(x);
    par[b] = a;
  }

  int ask(int a, int order) {
    a = find(a);
    assert(pbds[a].size() > order);
    return *pbds[a].find_by_order(order);
  }
};

int n, q;
vector<int> adj[kNode];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  int root;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a) {
      adj[i - 1].emplace_back(a - 1);
      adj[a - 1].emplace_back(i - 1);
    } else root = i - 1;
  }
  long long nn = 1LL * n * n;
  vector<Query> queries(q);
  vector<vector<int>> xquery_ids(n);
  vector<vector<int>> lcaquery_ids(n);
  for (int i = 0; i < q; i++) {
    auto& query = queries[i];
    cin >> query.order;
    query.order--;
    query.x = query.order / n;
    xquery_ids[query.x].emplace_back(i);
  }
  vector<int> sz(n, 1);
  function<void(int, int)> dfs_size = [&](int node, int p) {
    for (auto x : adj[node]) {
      if (x == p) continue;
      dfs_size(x, node);
      sz[node] += sz[x];
    }
  };
  dfs_size(root, root);
  BIT bit(n);
  function<void(int, int)> find_lca = [&](int node, int p) {
    if (node != p) {
      bit.update(p, sz[p] - sz[node]);
    }
    bit.update(node, sz[node]);
    // binser for each query in x == node
    for (auto qid : xquery_ids[node]) {
      auto& query = queries[qid];
      int yorder = query.order % n;
      int l = 0, r = n - 1;
      while (l <= r) {
        int m = (l + r) / 2;
        if (bit.ask(m) > yorder) {
          query.lca = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      query.y = yorder - bit.ask(query.lca - 1);
      lcaquery_ids[query.lca].emplace_back(qid);
    }

    for (auto x : adj[node]) {
      if (x == p) continue;
      find_lca(x, node);
    }
    bit.update(node, 0);
  };
  find_lca(root, root);
  UnionOrdered uord(n);
  function<void(int, int)> solve = [&](int node, int p) {
    for (auto x : adj[node]) {
      if (x == p) continue;
      solve(x, node);
      uord.merge(node, x);
    }
    for (auto qid : lcaquery_ids[node]) {
      auto& query = queries[qid];
      query.y = uord.ask(node, query.y);
    }
  };
  solve(root, root);
  for (auto& query : queries) {
    cout << nn * query.x + 1LL * n * query.lca + query.y << '\n';
  }

  return 0;
}
