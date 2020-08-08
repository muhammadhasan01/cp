// https://komiyam.hatenadiary.org/entry/20120117/1326730937
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long HASH;

const int MAX_N = 1e5;

int N, V;
vector<int> graph[2][MAX_N + 1];
int dist[MAX_N], dist2[MAX_N];
bool visited[MAX_N + 1];
HASH shaker[MAX_N];

void init(){
	scanf("%d", &N);
	for(int k=0; k<2; k++){
		for(int i=0; i<=N; i++){
			graph[k][i].clear();
		}
	}

	for(int k=0; k<2; k++){
		for(int i=0; i<N-1; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			graph[k][x].push_back(y);
			graph[k][y].push_back(x);
		}
	}
}

//flood fill
void dfs(int k, int v){
	visited[v] = true;
	for(int i=0; i<(int)graph[k][v].size(); i++){
		const int u = graph[k][v][i];
		if(!visited[u]){
			dist[u] = dist[v] + 1;
			dfs(k, u);
		}
	}
}

//センターのindexを返す。二つある場合はペアを、一つのときはsecondが-1。
pair<int,int> find_center(int k){
	memset(visited, false, sizeof(visited));
	dist[0] = 0;
	dfs(k, 0);

	int e = max_element(dist, dist + N) - dist;
	memset(visited, false, sizeof(visited));
	memcpy(dist2, dist, sizeof(dist));
	dist[e] = 0;
	dfs(k, e);

	memset(visited, false, sizeof(visited));
	memcpy(dist2, dist, sizeof(dist));
	e = max_element(dist, dist + N) - dist;
	dist[e] = 0;
	dfs(k, e);

	int diameter = *max_element(dist, dist+ N);

	pair<int,int> ret(-1,-1);
	for(int i=0; i<N; i++){
		if( (dist[i] == diameter/2 || dist2[i] == diameter/2) && dist[i] + dist2[i] == diameter){
			if(ret.first == -1){
				ret.first = i;
			}
			else {
				ret.second = i;
			}
		}
	}

	return ret;
}

//vを頂点とする部分木のハッシュ値を計算する。
HASH rec(int k, int v){
	HASH ret = 1;
	visited[v] = true;
	vector<HASH> hs;
	for(int i=0; i<(int)graph[k][v].size(); i++){
		const int u = graph[k][v][i];
		if(!visited[u]){
			hs.push_back(rec(k, u));
		}
	}
	sort(hs.begin(), hs.end());
	for(int i=0; i<(int)hs.size(); i++){
		ret += hs[i] * shaker[i];
	}

	return ret;
}


HASH calc_HASH(int k){
	pair<int,int> center = find_center(k);
	int root = center.first;

	//センターがふたつある場合ダミーを挿入。
	if(center.second != -1){
		root = N;
		const int v = center.first, u = center.second;

		graph[k][root].push_back(v);
		graph[k][root].push_back(u);

		*find(graph[k][v].begin(), graph[k][v].end(), u) = root;
		*find(graph[k][u].begin(), graph[k][u].end(), v) = root;
	}

	memset(visited, false, sizeof(visited));
	return rec(k, root);
}

//ノードのサイズは同じであることが前提。破壊的。
bool is_isomorhic(){
	return calc_HASH(0) == calc_HASH(1);
}

int main(){
	for(int i=0; i<MAX_N; i++){
		shaker[i] = rand();
		if (i <= 10)
			cout << shaker[i] << "\n";
	}
	// int T;
	// scanf("%d", &T);
	// for(;T--;){
	// 	init();
	// 	puts(is_isomorhic() ? "YES" : "NO");
	// }

	return 0;
}