int cnt[maxn];
void dfs(int v, int p, bool keep) {
  int mx = -1, bigChild = -1;
  for (auto u: g[v])
    if (u != p && sz[u] > mx)
      mx = sz[u], bigChild = u;
  for (auto u: g[v])
    if (u != p && u != bigChild)
      dfs(u, v, 0); // run a dfs on small childs and clear them from cnt
  if (bigChild != -1)
    dfs(bigChild, v, 1); // bigChild marked as big and not cleared from cnt
  for (auto u: g[v])
    if (u != p && u != bigChild)
      for (int p = tin[u]; p <= tout[u]; p++)
        cnt[col[ver[p]]]++;
  cnt[col[v]]++;
  // now cnt[c] is the number of vertices in subtree of vertex v that has color c.
  // You can answer the queries easily.
  if (keep == 0)
    for (int p = tin[v]; p <= tout[v]; p++)
      cnt[col[ver[p]]]--;
}