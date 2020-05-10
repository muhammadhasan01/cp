// author : m.hasan01 & donbasta
#include <bits/stdc++.h>
using namespace std;

// #define pii pair<int,int>;

const int N = 1e5+69;

int n,e;
vector<pair<int,int>> adj[N];
int dist[3][N];

struct jarak {
    int a,b,c;
	jarak() {a=b=c=0;}
	jarak(int aa, int bb, int cc) {a=aa; b=bb; c=cc;}
};

vector<jarak> ve;

bool ada(jarak x, jarak y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c<y.c;
		}
		return x.b<y.b;
	}
	return x.a<y.a;
}

void dijkstra(int source){
  for(int i=0; i<n; i++) dist[source][i] = (int) 1e9;
  dist[source][source] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  q.push({0, source});
  while (!q.empty()) {
      int v = q.top().second;
      int d_v = q.top().first;
      q.pop();
      if (d_v != dist[source][v])
          continue;
      for (auto edge : adj[v]) {
          int to = edge.first;
          int len = edge.second;
          if (dist[source][v] + len < dist[source][to]) {
              dist[source][to] = dist[source][v] + len;
              q.push({dist[source][to], to});
          }
      }
  }
}

vector<pair<pair<int, int>, int>> t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
      t[v] = vector<pair<pair<int, int>, int>>(1, {{ve[s].b, ve[s].c}, ve[s].a});
  } else {
      int mid = (s + e) >> 1;
      build(v << 1, s, mid);
      build(v << 1 | 1, mid + 1, e);
      merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(),
          t[v << 1 | 1].end(), back_inserter(t[v]));
  }
}

bool get(int v, int s, int e, int l, int r, int idx, bool min_one) {
  if (e < l || s > r) return false;
  if (l <= s && e <= r) {
      int leftz = 0, rightz = (int) t[v].size() - 1;
      int pos = -1;
      while (leftz <= rightz) {
          int mid = (leftz + rightz) >> 1;
          if (t[v][mid].first.first <= ve[idx].b) {
              leftz = mid + 1;
              pos = mid;
          } else {
              rightz = mid - 1;
          }
      }
      if (pos == -1) return false;
      for (int j = pos; j >= 0; j--) {
          if (!min_one && t[v][j].second < ve[idx].a) {
              min_one = true;
          }
          if (!min_one && t[v][j].first.first < ve[idx].b) {
              min_one = true;
          }
          if (min_one && t[v][j].first.second <= ve[idx].c) return true;
          if (t[v][j].first.second < ve[idx].c) return true;
      }
      return false;
  }
  int mid = (s + e) >> 1;
  bool ret = get(v << 1, s, mid, l, r, idx, min_one);
  ret |= get(v << 1 | 1, mid + 1, e, l, r, idx, min_one);
  return ret;
}

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 cin >> n >> e;
 for(int i=0; i<e; i++){
 	int a,b,w;
 	cin >> a >> b >> w;
 	adj[a].push_back({b,w});
 	adj[b].push_back({a,w});
 }

 for(int i=0; i<3; i++){
 	dijkstra(i);
 }

 for(int i=0; i<n; i++){
 	jarak t = jarak(dist[0][i], dist[1][i], dist[2][i]);
 	ve.push_back(t);
 }

	sort(ve.begin(),ve.end(),ada);

	build(1, 0, n - 1);

  int ans = 0;
  for(int i = n - 1; i > 0; i--){
      bool min_one = (ve[i].a > ve[i - 1].a);
      if (get(1, 0, n - 1, 0, i - 1, i, min_one)) ans++;
  }
  cout << n - ans << '\n';

}