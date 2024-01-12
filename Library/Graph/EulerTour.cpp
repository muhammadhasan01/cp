struct EulerTour {
    int n;
    vector<int> tin;
    vector<int> tout;
    vector<int> eul;
 
    EulerTour(int t_n) : n(t_n), tin(t_n), tout(t_n), eul(2 * t_n + 1) {}
    EulerTour(int root, vector<vector<int>>& adj) : EulerTour((int) adj.size()) {
        build(root, adj);
    }
 
    void build(int root, vector<vector<int>>& adj) {
        int tim = 0;
        
        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = ++tim;
            eul[tim] = u;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
            }
            tout[u] = ++tim;
            eul[tim] = u;
        };
        
        dfs(root, root);
    }
};