template<typename T = int>
struct CentroidDecomposition {
    int nodes;
    vector<vector<T>> adj;
    vector<deque<int>> dist;
    vector<int> parc, sz;
    vector<int> checked;
    
    CentroidDecomposition(int n) {
        nodes = 0;
        adj.assign(n, vector<T>());
        dist.assign(n, deque<int>());
        parc.assign(n, 0);
        sz.assign(n, 0);
        checked.assign(n, 0);
    }

    void add_edge(int u, T v) {
        adj[u].emplace_back(v);
    }

    void get_size_subtree(int u, int p) {
        nodes++;
        sz[u] = 1;
        for (auto& v : adj[u]) {
            if (v == p || checked[v]) {
                continue;
            }
            get_size_subtree(v, u);
            sz[u] += sz[v];
        }
    }

    void get_distances(int u, int p, int d) {
        dist[u].emplace_front(d);
        for (auto& v : adj[u]) {
            if (v == p || checked[v]) {
                continue;
            }
            get_distances(v, u, d + 1);
        }
    }

    int centroid(int u, int p) {
        for (auto& v : adj[u]) {
            if (v == p || checked[v]) {
                continue;
            }
            if (sz[v] > nodes) {
                return centroid(v, u);
            }
        }
        return u;
    }

    void decompose(int u, int p) {
        nodes = 0;
        get_size_subtree(u, u);
        nodes /= 2;
        int v = centroid(u, u);
        checked[v] = true;
        get_distances(v, v, 0);
        parc[v] = p;
        for (auto& w : adj[v]) {
            if (checked[w]) {
                continue;
            }
            decompose(w, v);
        }
    }
};