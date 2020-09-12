const int N = 2e5 + 10;

int n;
vector<int> adj[N];
int tin[N], low[N], comp[N];
int timer, compNum;
vector<int> st;

void dfs_scc(int node, int p) {
    st.pb(node);
    tin[node] = low[node] = ++timer;
    for (auto x : adj[node]) {
        if (x == p) continue; // comment this line for directed graph
        if (tin[x]) {
            low[node] = min(low[node], tin[x]); 
        } else {
            dfs_scc(x, node);
            low[node] = min(low[node], low[x]);
        }
    }
    if (low[node] == tin[node]) {
        compNum++;
        while (st.back() != node) {
            comp[st.back()] = compNum;
            st.pop_back();
        }
        comp[st.back()] = compNum;
        st.pop_back();
    }
}
void tarjan(){
    for (int i = 1; i <= n; i++) {
        tin[i] = low[i] = comp[i] = 0;
    }
    timer = compNum = 0;
    st.clear();
    for (int i = 1; i <= n; i++) {
        if (tin[i] == 0) {
            dfs_scc(i, i);
        }
    }
}