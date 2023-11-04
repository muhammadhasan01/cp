struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> comp;
    int numComponent = 0;
    
    SCC(int t_n) : n(t_n), adj(t_n), comp(t_n, -1) {}
    SCC(const vector<vector<int>>& t_adj) : adj(t_adj) {
        n = t_adj.size();
        comp.assign(n, -1);
    }
 
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
    }
 
    void build(bool isDirected) {
        vector<int> tin(n), low(n);
        vector<bool> onStack(n);
        stack<int> st;
        int timer = 0;
        function<void(int, int)> tarjan = [&](int u, int p) {
            tin[u] = low[u] = ++timer;
            st.emplace(u);
            onStack[u] = true;
            for (int v : adj[u]) {
                if (!isDirected && v == p) {
                    continue;
                }
                if (tin[v] == 0) {
                    tarjan(v, u);
                    low[u] = min(low[u], low[v]);
                } else if (onStack[v]) {
                    low[u] = min(low[u], tin[v]);
                }
            }
            if (tin[u] != low[u]) {
                return;
            }
            int w = 0;
            do {
                w = st.top();
                st.pop();
                onStack[w] = 0;
                comp[w] = numComponent;
            } while (w != u && !st.empty());
            numComponent++;
        };
        for (int u = 0; u < n; u++) {
            if (tin[u] == 0) {
                tarjan(u, u);
            }
        }
    }
};