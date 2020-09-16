// Time Complexity: O(V + E)

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int tin[N], low[N], timer = 0;
int comp[N], numComponent;
stack<int> st;
bool onStack[N];

void tarjan(int u) {
    tin[u] = low[u] = ++timer;
    st.emplace(u); onStack[u] = true;
    for (auto v : adj[u]) {
        if (tin[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] != low[u]) return;
    int w = 0; numComponent++;
    do {
        w = st.top(); st.pop();
        onStack[w] = 0;
        comp[w] = numComponent;
    } while (w != u && !st.empty());
}

void SCC() {
    for (int i = 1; i <= n; i++) {
        if (tin[i]) continue;
        tarjan(i);
    }
}