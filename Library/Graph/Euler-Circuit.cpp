// all degree must be even for circuit
// for euler path, there must be 2 or 0 odd degree
vector<int> euler_circuit(int s) {
    vector<int> ret;
    vector<int> st;
    st.emplace_back(s);
    while (!st.empty()) {
        int u = st.back();
        if (adj[u].empty()) {
            ret.emplace_back(u);
            st.pop_back();
        } else {
            int v = adj[u].front();
            st.emplace_back(v);
            adj[u].pop_front();
        }
    }
    return ret;
}