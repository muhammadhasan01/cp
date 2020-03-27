#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, q;
vector<int> par;
vector<int> opp;
vector<string> s;

int get_idx(const string& str) {
  int l = 0, r = n - 1, at = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (s[mid] >= str) {
      r = mid - 1;
      at = mid;
    } else {
      l = mid + 1;
    }
  }
  return at;
}

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

int fopp(int x) {
  int px = fpar(x);
  if (opp[px] == -1) return -1;
  return (opp[px] = fpar(opp[px]));
}

bool make_union(int x, int y) {
  int px = fpar(x);
  int py = fpar(y);
  int pX = fopp(x);
  int pY = fopp(y);

  // already opposite
  if (px == pY || pX == py) return false;

  // union
  par[py] = px;

  // union the opposite sets
  if (pX < pY) swap(pX, pY);
  if (pX != -1 && pY != -1) {
    par[pY] = pX;
  }

  // set link to opposite
  opp[px] = pX;
  return true;
}

bool make_opposite(int x, int y) {
  int px = fpar(x);
  int py = fpar(y);
  int pX = fopp(x);
  int pY = fopp(y);

  // x and y are in the same set
  // or their opposite is in the same set
  if (px == py || (pX == pY && pX != -1)) return false;

  // union of x and opp(y)
  if (pY != -1) {
    par[pY] = px;
  }

  // union of y and opp(x)
  if (pX != -1) {
    par[pX] = py;
  }

  // set links to opposite
  opp[px] = py;
  opp[py] = px;
  return true;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m >> q;
  s.resize(n);
  par.resize(n);
  opp.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    par[i] = i;
    opp[i] = -1;
  }
  sort(s.begin(), s.end());
  for (int i = 1; i <= m; i++) {
    int t;
    string u, v;
    cin >> t >> u >> v;
    int id_1 = get_idx(u);
    int id_2 = get_idx(v);
    if (t == 1) {
      cout << (make_union(id_1, id_2) ? "YES" : "NO") << '\n';
    } else {
      cout << (make_opposite(id_1, id_2) ? "YES" : "NO") << '\n';
    }
  }
  while (q--) {
    string u, v;
    cin >> u >> v;
    int id_1 = get_idx(u);
    int id_2 = get_idx(v);
    if (fpar(id_1) == fpar(id_2)) {
      cout << 1 << '\n';
    } else if (fpar(id_1) == fopp(id_2)) {
      cout << 2 << '\n'; 
    } else {
      cout << 3 << '\n';
    }
  }

  return 0;
}