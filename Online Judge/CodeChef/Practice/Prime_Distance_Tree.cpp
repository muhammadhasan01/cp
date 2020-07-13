#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int L = ceil(log2(N)) + 2;

int n;
int nodes;
vector<int> adj[N];
vector<vector<int>> cent[N];
int sz[N], dist[N];
bool checked[N], notPrime[N];
vector<int> primes;

void dfs(int u, int p) {
    nodes++; sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p, int d, vector<int>& cur) {
    cur.emplace_back(d);
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        dfs2(v, u, d + 1, cur);
    }
}

int centroid(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        if (sz[v] > nodes) return centroid(v, u);
    }
    return u;
}

void decompose(int u) {
    nodes = 0; dfs(u, u); nodes /= 2;
    int v = centroid(u, u);
    checked[v] = 1;
    int len = adj[v].size();
    for (auto& w : adj[v]) {
        if (checked[w]) continue;
        vector<int> cur;
        dfs2(w, w, 1, cur);
        cent[v].emplace_back(cur);
    }
    for (auto& w : adj[v]) {
        if (checked[w]) continue;
        decompose(w);
    }
}

long long getResult(int comp) {
    long long ret = 0;
    for (auto& part : cent[comp]) {
        for (auto& d : part) dist[d]++;
    }
    for (auto& part : cent[comp]) {
        for (auto& d : part) dist[d]--;
        for (auto& d : part) {
            for (auto& prime : primes) {
                if (prime - d < 0) continue;
                if (prime == d) {
                    ret += 2LL;
                } else {
                    ret += (1LL) * dist[prime - d];
                }
            }
        }
        for (auto& d : part) dist[d]++;
    }
    for (auto& part : cent[comp]) {
        for (auto& d : part) dist[d]--;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int i = 2; i <= n; i++) {
        if (notPrime[i]) continue;
        primes.emplace_back(i);
        for (int j = i + i; j <= n; j += i) {
            notPrime[j] = 1;
        }
    }
    decompose(1);
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += getResult(i);
    }
    answer /= 2;
    long double div = (long double) n * (n - 1) * 0.5;
    long double m = answer;
    cout << fixed << setprecision(12) << answer / div << '\n';

    return 0;
}