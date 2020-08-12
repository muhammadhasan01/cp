// Author : donbasta
#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 1e5 + 10;
const int INF = 1e9;
 
int n, m, k;
int gr[N + 5];
vector<int> to[N + 5], from[N + 5], pos, topo;
bool vis[N + 5]; 
 
bool forbid[N];
 
int mex(vector<int> ve) {
  sort(ve.begin(), ve.end());
  int ret = 0;
  for (auto x : ve){
    if (ret == x) ret++;
    else if (x > ret) break;
  }
  return ret;
}
 
void dfs(int node){
  vis[node] = true;
  for(auto i : to[node]){
    if(!vis[i]){
      dfs(i);
    }
  }
  topo.push_back(node);
}
 
void toposort(){
  dfs(1);
  reverse(topo.begin(), topo.end());
}
 
void isi() {
  for(auto i : topo) {
    if (forbid[i] || i == 1) continue;
    vector<int> lol;
    for(auto j : from[i]) {
      if(gr[j] >= 0)
        lol.push_back(gr[j]);
    }
    gr[i] = mex(lol);
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  memset(gr, -1, sizeof(gr));
 
  cin >> n >> m >> k;
  bool lol = false;
  for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    to[b].push_back(a);
    from[a].push_back(b);
    if (b == 1){
      forbid[a] = 1;
      gr[a] = -1;
    }
  }
  gr[1] = 0;
  toposort();
  isi();
 
  for(int i = 0; i < k; i++) {
    int a;
    cin >> a;
    pos.push_back(a);
    if (forbid[a]){
      cout << "Chanek\n";
      return 0; 
    }
  }
  int ok = 0;
  for(auto i : pos) {
    ok ^= gr[i];
  }
  cout << (ok ? "Chanek" : "Ganesh") << '\n';
  return 0;
}